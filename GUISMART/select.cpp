#include "select.h"
#include "ui_select.h"
#include <QVBoxLayout>
#include <QCheckBox>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <cstdlib>


 QCheckBox** ArrayCheck= new QCheckBox*[200];
 QString nameAlgorithms[200];

Selezione::Selezione(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Selezione)
{
    ui->setupUi(this);

    QVBoxLayout* box2= new QVBoxLayout(this);

    system("rm listaSelezionati.txt");
    system("./select -which >>listaSelezionati.txt");


    QFile inputFile("listaAlgoritmi.txt");
    int j=0;
    if (inputFile.open(QIODevice::ReadOnly)){
       QTextStream in(&inputFile);
       while (!in.atEnd()){
          QString line = in.readLine();
          nameAlgorithms[j]=line;
          ArrayCheck[j] = new QCheckBox(nameAlgorithms[j],this);
          box2->addWidget(ArrayCheck[j]);
          j++;
       }
       inputFile.close();
    }

    ui->scrollContents->setLayout(box2);

   QFile inputFile1("listaSelezionati.txt");
   QString newLine;
   if (inputFile1.open(QIODevice::ReadOnly)){
      QTextStream in(&inputFile1);
      while (!in.atEnd()){
         QString line = in.readLine();
         newLine = line.replace("\t","");
         for(int k=0;k<j;k++){
             if(newLine==nameAlgorithms[k]){
                 ArrayCheck[k]->click();
             }
         }
      }
      inputFile.close();
   }
//    qDebug() <<stringa.mid(stringa.indexOf("-bf")+5,1);

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
/*
    if(ArrayCheck[0]->isChecked()) system("./select bf");
    if(ArrayCheck[1]->isChecked()) system("./select ");
    if(ArrayCheck[2]->isChecked()) system("./select ");
    if(ArrayCheck[3]->isChecked()) system("./select ");
    if(ArrayCheck[4]->isChecked()) system("./select ");
    if(ArrayCheck[5]->isChecked()) system("./select ");
    if(ArrayCheck[6]->isChecked()) system("./select ");
    if(ArrayCheck[7]->isChecked()) system("./select ");
    if(ArrayCheck[8]->isChecked()) system("./select ");
    if(ArrayCheck[9]->isChecked()) system("./select ");
    if(ArrayCheck[10]->isChecked()) system("./select ");
    if(ArrayCheck[11]->isChecked()) system("./select ");
    if(ArrayCheck[12]->isChecked()) system("./select ");
    if(ArrayCheck[13]->isChecked()) system("./select ");
    if(ArrayCheck[14]->isChecked()) system("./select ");
    if(ArrayCheck[15]->isChecked()) system("./select ");
    if(ArrayCheck[16]->isChecked()) system("./select ");
    if(ArrayCheck[17]->isChecked()) system("./select ");
    if(ArrayCheck[18]->isChecked()) system("./select ");
    if(ArrayCheck[19]->isChecked()) system("./select ");
    if(ArrayCheck[20]->isChecked()) system("./select ");
    if(ArrayCheck[21]->isChecked()) system("./select ");
    if(ArrayCheck[22]->isChecked()) system("./select ");
    if(ArrayCheck[23]->isChecked()) system("./select ");
    if(ArrayCheck[24]->isChecked()) system("./select ");
    if(ArrayCheck[25]->isChecked()) system("./select ");
    if(ArrayCheck[26]->isChecked()) system("./select ");
    if(ArrayCheck[27]->isChecked()) system("./select ");
    if(ArrayCheck[28]->isChecked()) system("./select ");
    if(ArrayCheck[29]->isChecked()) system("./select ");
    if(ArrayCheck[30]->isChecked()) system("./select ");
    if(ArrayCheck[31]->isChecked()) system("./select ");
    if(ArrayCheck[32]->isChecked()) system("./select ");
    if(ArrayCheck[33]->isChecked()) system("./select ");
    if(ArrayCheck[34]->isChecked()) system("./select ");
    if(ArrayCheck[35]->isChecked()) system("./select ");
    if(ArrayCheck[36]->isChecked()) system("./select ");
    if(ArrayCheck[37]->isChecked()) system("./select ");
    if(ArrayCheck[38]->isChecked()) system("./select ");
    if(ArrayCheck[39]->isChecked()) system("./select ");
    if(ArrayCheck[40]->isChecked()) system("./select ");
    if(ArrayCheck[41]->isChecked()) system("./select ");
    if(ArrayCheck[42]->isChecked()) system("./select ");
    if(ArrayCheck[43]->isChecked()) system("./select ");
    if(ArrayCheck[44]->isChecked()) system("./select ");
    if(ArrayCheck[45]->isChecked()) system("./select ");
    if(ArrayCheck[46]->isChecked()) system("./select ");
    if(ArrayCheck[47]->isChecked()) system("./select ");
    if(ArrayCheck[48]->isChecked()) system("./select ");
    if(ArrayCheck[49]->isChecked()) system("./select ");
    if(ArrayCheck[50]->isChecked()) system("./select ");
    if(ArrayCheck[51]->isChecked()) system("./select ");
    if(ArrayCheck[52]->isChecked()) system("./select ");
    if(ArrayCheck[53]->isChecked()) system("./select ");
    if(ArrayCheck[54]->isChecked()) system("./select ");
    if(ArrayCheck[55]->isChecked()) system("./select ");
    if(ArrayCheck[56]->isChecked()) system("./select ");
    if(ArrayCheck[57]->isChecked()) system("./select ");
    if(ArrayCheck[58]->isChecked()) system("./select ");
    if(ArrayCheck[59]->isChecked()) system("./select ");
    if(ArrayCheck[60]->isChecked()) system("./select ");
    if(ArrayCheck[61]->isChecked()) system("./select ");
    if(ArrayCheck[62]->isChecked()) system("./select ");
    if(ArrayCheck[63]->isChecked()) system("./select ");
    if(ArrayCheck[64]->isChecked()) system("./select ");
    if(ArrayCheck[65]->isChecked()) system("./select ");
    if(ArrayCheck[66]->isChecked()) system("./select ");
    if(ArrayCheck[67]->isChecked()) system("./select ");
    if(ArrayCheck[68]->isChecked()) system("./select ");
    if(ArrayCheck[69]->isChecked()) system("./select ");
    if(ArrayCheck[70]->isChecked()) system("./select ");
    if(ArrayCheck[71]->isChecked()) system("./select ");
    if(ArrayCheck[72]->isChecked()) system("./select ");
    if(ArrayCheck[73]->isChecked()) system("./select ");
    if(ArrayCheck[74]->isChecked()) system("./select ");
    if(ArrayCheck[75]->isChecked()) system("./select ");
    if(ArrayCheck[76]->isChecked()) system("./select ");
    if(ArrayCheck[77]->isChecked()) system("./select ");
    if(ArrayCheck[78]->isChecked()) system("./select ");
    if(ArrayCheck[79]->isChecked()) system("./select ");
    if(ArrayCheck[80]->isChecked()) system("./select ");
    if(ArrayCheck[81]->isChecked()) system("./select ");
    if(ArrayCheck[82]->isChecked()) system("./select ");
    if(ArrayCheck[83]->isChecked()) system("./select ");
    if(ArrayCheck[84]->isChecked()) system("./select ");
    if(ArrayCheck[85]->isChecked()) system("./select ");


*/
    //  ArrayCheck[0]->add
}
