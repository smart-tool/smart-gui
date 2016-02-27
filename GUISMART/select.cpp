#include "select.h"
#include "ui_select.h"
#include <QVBoxLayout>
#include <QCheckBox>

 QCheckBox** ArrayCheck= new QCheckBox*[86];

Selezione::Selezione(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Selezione)
{
    ui->setupUi(this);

    QVBoxLayout* box2= new QVBoxLayout(this);






    ArrayCheck[0]= new QCheckBox("bf",this);
    box2->addWidget(ArrayCheck[0]);

    ArrayCheck[1]= new QCheckBox("aut",this);
    box2->addWidget(ArrayCheck[1]);

    ArrayCheck[2]= new QCheckBox("mp",this);
    box2->addWidget(ArrayCheck[2]);

    ArrayCheck[3]= new QCheckBox("kmp",this);
    box2->addWidget(ArrayCheck[3]);

    ArrayCheck[4]= new QCheckBox("bm",this);
    box2->addWidget(ArrayCheck[4]);

    ArrayCheck[5]= new QCheckBox("hot",this);
    box2->addWidget(ArrayCheck[5]);

    ArrayCheck[6]= new QCheckBox("ag",this);
    box2->addWidget(ArrayCheck[6]);

    ArrayCheck[7]= new QCheckBox("kr",this);
    box2->addWidget(ArrayCheck[7]);

    ArrayCheck[8]= new QCheckBox("zt",this);
    box2->addWidget(ArrayCheck[8]);

    ArrayCheck[9]= new QCheckBox("om",this);
    box2->addWidget(ArrayCheck[9]);

    ArrayCheck[10]= new QCheckBox("ms",this);
    box2->addWidget(ArrayCheck[10]);

    ArrayCheck[11]= new QCheckBox("qs",this);
    box2->addWidget(ArrayCheck[11]);

    ArrayCheck[12]= new QCheckBox("ac",this);
    box2->addWidget(ArrayCheck[12]);

    ArrayCheck[13]= new QCheckBox("tw",this);
    box2->addWidget(ArrayCheck[13]);

    ArrayCheck[14]= new QCheckBox("tunedbm",this);
    box2->addWidget(ArrayCheck[14]);

    ArrayCheck[15]= new QCheckBox("col",this);
    box2->addWidget(ArrayCheck[15]);

    ArrayCheck[16]= new QCheckBox("smith",this);
    box2->addWidget(ArrayCheck[16]);

    ArrayCheck[17]= new QCheckBox("gg",this);
    box2->addWidget(ArrayCheck[17]);

    ArrayCheck[18]= new QCheckBox("raita",this);
    box2->addWidget(ArrayCheck[18]);

    ArrayCheck[19]= new QCheckBox("smoa",this);
    box2->addWidget(ArrayCheck[19]);

    ArrayCheck[20]= new QCheckBox("rf",this);
    box2->addWidget(ArrayCheck[20]);

    ArrayCheck[21]= new QCheckBox("so",this);
    box2->addWidget(ArrayCheck[21]);

    ArrayCheck[22]= new QCheckBox("sa",this);
    box2->addWidget(ArrayCheck[22]);

    ArrayCheck[23]= new QCheckBox("nsn",this);
    box2->addWidget(ArrayCheck[23]);

    ArrayCheck[24]= new QCheckBox("simon",this);
    box2->addWidget(ArrayCheck[24]);

    ArrayCheck[25]= new QCheckBox("tbm",this);
    box2->addWidget(ArrayCheck[25]);

    ArrayCheck[26]= new QCheckBox("rcol",this);
    box2->addWidget(ArrayCheck[26]);

    ArrayCheck[27]= new QCheckBox("trf",this);
    box2->addWidget(ArrayCheck[27]);

    ArrayCheck[28]= new QCheckBox("fdm",this);
    box2->addWidget(ArrayCheck[28]);

    ArrayCheck[29]= new QCheckBox("bdm",this);
    box2->addWidget(ArrayCheck[29]);

    ArrayCheck[30]= new QCheckBox("skip",this);
    box2->addWidget(ArrayCheck[30]);

    ArrayCheck[31]= new QCheckBox("askip",this);
    box2->addWidget(ArrayCheck[31]);

    ArrayCheck[32]= new QCheckBox("kmpskip",this);
    box2->addWidget(ArrayCheck[32]);

    ArrayCheck[33]= new QCheckBox("bndml",this);
    box2->addWidget(ArrayCheck[33]);

    ArrayCheck[34]= new QCheckBox("br",this);
    box2->addWidget(ArrayCheck[34]);

    ArrayCheck[35]= new QCheckBox("bom",this);
    box2->addWidget(ArrayCheck[35]);

    ArrayCheck[36]= new QCheckBox("dfdm",this);
    box2->addWidget(ArrayCheck[36]);

    ArrayCheck[37]= new QCheckBox("akc",this);
    box2->addWidget(ArrayCheck[37]);

    ArrayCheck[38]= new QCheckBox("fs",this);
    box2->addWidget(ArrayCheck[38]);

    ArrayCheck[39]= new QCheckBox("sdndm",this);
    box2->addWidget(ArrayCheck[39]);

    ArrayCheck[40]= new QCheckBox("tndm",this);
    box2->addWidget(ArrayCheck[40]);

    ArrayCheck[41]= new QCheckBox("lbndm",this);
    box2->addWidget(ArrayCheck[41]);

    ArrayCheck[42]= new QCheckBox("svm0",this);
    box2->addWidget(ArrayCheck[42]);

    ArrayCheck[43]= new QCheckBox("ffs",this);
    box2->addWidget(ArrayCheck[43]);

    ArrayCheck[44]= new QCheckBox("bfs",this);
    box2->addWidget(ArrayCheck[44]);

    ArrayCheck[45]= new QCheckBox("ts",this);
    box2->addWidget(ArrayCheck[45]);

    ArrayCheck[46]= new QCheckBox("ssabs",this);
    box2->addWidget(ArrayCheck[46]);

    ArrayCheck[47]= new QCheckBox("ww",this);
    box2->addWidget(ArrayCheck[47]);

    ArrayCheck[48]= new QCheckBox("ldm",this);
    box2->addWidget(ArrayCheck[48]);

    ArrayCheck[49]= new QCheckBox("bndmq2",this);
    box2->addWidget(ArrayCheck[49]);

    ArrayCheck[50]= new QCheckBox("sdndm2",this);
    box2->addWidget(ArrayCheck[50]);

    ArrayCheck[51]= new QCheckBox("sbndm-bmh",this);
    box2->addWidget(ArrayCheck[51]);

    ArrayCheck[52]= new QCheckBox("bmh-sdndm",this);
    box2->addWidget(ArrayCheck[52]);

    ArrayCheck[53]= new QCheckBox("fndm",this);
    box2->addWidget(ArrayCheck[53]);

    ArrayCheck[54]= new QCheckBox("bww",this);
    box2->addWidget(ArrayCheck[54]);

    ArrayCheck[55]= new QCheckBox("faoso2",this);
    box2->addWidget(ArrayCheck[55]);

    ArrayCheck[56]= new QCheckBox("aoso2",this);
    box2->addWidget(ArrayCheck[56]);

    ArrayCheck[57]= new QCheckBox("tvsbs",this);
    box2->addWidget(ArrayCheck[57]);

    ArrayCheck[58]= new QCheckBox("pbmh",this);
    box2->addWidget(ArrayCheck[58]);

    ArrayCheck[59]= new QCheckBox("ildm1",this);
    box2->addWidget(ArrayCheck[59]);

    ArrayCheck[60]= new QCheckBox("ildm2",this);
    box2->addWidget(ArrayCheck[60]);

    ArrayCheck[61]= new QCheckBox("fjs",this);
    box2->addWidget(ArrayCheck[61]);

    ArrayCheck[62]= new QCheckBox("hash3",this);
    box2->addWidget(ArrayCheck[62]);

    ArrayCheck[63]= new QCheckBox("tsw",this);
    box2->addWidget(ArrayCheck[63]);

    ArrayCheck[64]= new QCheckBox("blim",this);
    box2->addWidget(ArrayCheck[64]);

    ArrayCheck[65]= new QCheckBox("graspm",this);
    box2->addWidget(ArrayCheck[65]);

    ArrayCheck[66]= new QCheckBox("ssef",this);
    box2->addWidget(ArrayCheck[66]);

    ArrayCheck[67]= new QCheckBox("ebom",this);
    box2->addWidget(ArrayCheck[67]);

    ArrayCheck[68]= new QCheckBox("fbom",this);
    box2->addWidget(ArrayCheck[68]);

    ArrayCheck[69]= new QCheckBox("sebom",this);
    box2->addWidget(ArrayCheck[69]);

    ArrayCheck[70]= new QCheckBox("sfbom",this);
    box2->addWidget(ArrayCheck[70]);

    ArrayCheck[71]= new QCheckBox("sdbm",this);
    box2->addWidget(ArrayCheck[71]);

    ArrayCheck[72]= new QCheckBox("fsdbdm",this);
    box2->addWidget(ArrayCheck[72]);

    ArrayCheck[73]= new QCheckBox("bndmq2",this);
    box2->addWidget(ArrayCheck[73]);

    ArrayCheck[74]= new QCheckBox("sbndmq2",this);
    box2->addWidget(ArrayCheck[74]);

    ArrayCheck[75]= new QCheckBox("ufndmq2",this);
    box2->addWidget(ArrayCheck[75]);

    ArrayCheck[76]= new QCheckBox("sabp",this);
    box2->addWidget(ArrayCheck[76]);

    ArrayCheck[77]= new QCheckBox("bp2ww",this);
    box2->addWidget(ArrayCheck[77]);

    ArrayCheck[78]= new QCheckBox("bpww2",this);
    box2->addWidget(ArrayCheck[78]);

    ArrayCheck[79]= new QCheckBox("kdndm",this);
    box2->addWidget(ArrayCheck[79]);

    ArrayCheck[80]= new QCheckBox("ksa",this);
    box2->addWidget(ArrayCheck[80]);

    ArrayCheck[81]= new QCheckBox("bxs",this);
    box2->addWidget(ArrayCheck[81]);

    ArrayCheck[82]= new QCheckBox("fsbndm2 0",this);
    box2->addWidget(ArrayCheck[82]);

    ArrayCheck[83]= new QCheckBox("ssecp",this);
    box2->addWidget(ArrayCheck[83]);

    ArrayCheck[84]= new QCheckBox("bsdm",this);
    box2->addWidget(ArrayCheck[84]);

    ArrayCheck[85]= new QCheckBox("epsm",this);
    box2->addWidget(ArrayCheck[85]);




    ui->scrollContents->setLayout(box2);






}

Selezione::~Selezione()
{
    delete ui;
}

void Selezione::on_pushButton_clicked()
{
    system("./select -which");
}

void Selezione::on_pushButton_2_clicked()
{

    for(int i=0 ; i<86 ; i++){
        if(ArrayCheck[i]->isChecked()){system("./select -which");  }

    }


    //  ArrayCheck[0]->add
}
