#include "selectalgwindow.h"
#include "ui_selectalgwindow.h"

#include <QVBoxLayout>
#include <QCheckBox>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <cstdlib>

#include <QDir>

#define NumAlgo 500                        //Define the number of algorithm.
QCheckBox *arrayCheckBox[NumAlgo];         //Declary array of checkBox.
int EXECUTE[NumAlgo];                      //Declare EXECTUE array with the state of alrgorithm (0/1).
char *ALGO_NAME[NumAlgo];                  //Declare array ALGO_NAME with the name of all string matching algorithms.

QString __pathSmartGUI = QDir::homePath() + "/smartGUI";
QString __pathSmart = "";

void getAlgo(char *ALGO_NAME[], int EXECUTE[]) {
    QByteArray tmpByteArray = __pathSmart.toLatin1() + "/source/algorithms.h";
    const char * pathSmartConst = tmpByteArray.data();

    FILE *fp = fopen(pathSmartConst, "r");
    char c; int i=0;
    while( (c=getc(fp)) != EOF )
        if(c=='#') {
            EXECUTE[i] = (getc(fp)-'0');
            getc(fp);getc(fp);
            ALGO_NAME[i] = (char*) malloc (sizeof(char)*20);
            int j = 0;
            while((c=getc(fp))!=' ') ALGO_NAME[i][j++]=c;
            ALGO_NAME[i][j]='\0';
            i++;
        }
    while(i<NumAlgo) ALGO_NAME[i++]=NULL;
    fclose(fp);
}

SelectAlgWindow::SelectAlgWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectAlgWindow){
    ui->setupUi(this);

    QFile pathSmartFile(__pathSmartGUI + "/pathSource.conf");

    if(pathSmartFile.exists()){
        if (pathSmartFile.open(QIODevice::ReadOnly)) {
            QTextStream in(&pathSmartFile);
            __pathSmart = in.readAll();
            pathSmartFile.close();
        }
    }

    //Load array.
    getAlgo(ALGO_NAME,EXECUTE);

    //Declare new Layout to add the new CheckBox.
    QVBoxLayout *listCheckBox = new QVBoxLayout();

    //Create checkBox with the name of algorithm and check if the alg is enabled.
    for(int i=0;i<NumAlgo;i++){
        if(ALGO_NAME[i]){
            arrayCheckBox[i] = new QCheckBox(ALGO_NAME[i],this);

            if(EXECUTE[i])
                arrayCheckBox[i]->setChecked(true);

            listCheckBox->addWidget(arrayCheckBox[i]);
        }
    }

    //Apply layout.
    ui->scrollAreaWidgetContents->setLayout(listCheckBox);

}

SelectAlgWindow::~SelectAlgWindow() {
    delete ui;
}


void SelectAlgWindow::on_checkAll_Button_clicked(){
    for(int i=0;i<NumAlgo;i++)
        if(ALGO_NAME[i])
            arrayCheckBox[i]->setChecked(true); //Check all alrgorithm.
}

void SelectAlgWindow::on_uncheckAll_Button_clicked(){
    for(int i=0;i<NumAlgo;i++)
        if(ALGO_NAME[i])
            arrayCheckBox[i]->setChecked(false); //Unheck all alrgorithm.
}

void SelectAlgWindow::on_update_Button_clicked(){

    //Update EXECUTE vector.
    for(int i=0;i<NumAlgo;i++){
        if(ALGO_NAME[i]){
            if(arrayCheckBox[i]->isChecked())
                EXECUTE[i]=1;
            else
                EXECUTE[i]=0;
        }
    }

    //The following code was copied from smart.
    int order[NumAlgo];
    for(int i=0; i<NumAlgo; i++) order[i] = i;

    for(int i=0; i<NumAlgo; i++){
        for(int j=0; j<NumAlgo; j++){
            if( ALGO_NAME[order[j]] && ALGO_NAME[order[j+1]] && strcmp( ALGO_NAME[order[j]] , ALGO_NAME[order[j+1]])>0 ){
                int tmp = order[j];
                order[j] = order[j+1];
                order[j+1] = tmp;
            }
        }
    }

    //Update / Write the algorithms.h file.
    QByteArray tmpByteArray = __pathSmart.toLatin1() + "/source/algorithms.h";
    const char * pathSmartConst = tmpByteArray.data();
    FILE *fp = fopen(pathSmartConst, "w");

    for(int j=0; j<NumAlgo; j++)
        if(ALGO_NAME[j])
            fprintf(fp,"#%d #%s \n", EXECUTE[order[j]], ALGO_NAME[order[j]] );

    fclose(fp);

    //Show a dialog.
    QMessageBox::information(this,"Done!","The list of algorithms has been updated.");
}

