#include "select.h"
#include "ui_select.h"
#include <QVBoxLayout>
#include <QCheckBox>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <cstdlib>


 QCheckBox** ArrayCheck= new QCheckBox*[86];

Selezione::Selezione(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Selezione)
{
    ui->setupUi(this);

    QVBoxLayout* box2= new QVBoxLayout(this);




    system("rm file.txt");
    system("./select -which >>file.txt");

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

//    ArrayCheck[20]= new QCheckBox("rf",this);
//    box2->addWidget(ArrayCheck[20]);

    ArrayCheck[21]= new QCheckBox("so",this);
    box2->addWidget(ArrayCheck[21]);

//    ArrayCheck[22]= new QCheckBox("sa",this);
//    box2->addWidget(ArrayCheck[22]);

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

 //   ArrayCheck[29]= new QCheckBox("bdm",this);
 //   box2->addWidget(ArrayCheck[29]);

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

//    ArrayCheck[36]= new QCheckBox("dfdm",this);
//    box2->addWidget(ArrayCheck[36]);

    ArrayCheck[37]= new QCheckBox("akc",this);
    box2->addWidget(ArrayCheck[37]);

    ArrayCheck[38]= new QCheckBox("fs",this);
    box2->addWidget(ArrayCheck[38]);

//    ArrayCheck[39]= new QCheckBox("sdndm",this);
//    box2->addWidget(ArrayCheck[39]);

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

 //   ArrayCheck[72]= new QCheckBox("fsdbdm",this);
 //   box2->addWidget(ArrayCheck[72]);

    ArrayCheck[73]= new QCheckBox("bndmq2",this);
    box2->addWidget(ArrayCheck[73]);

    ArrayCheck[74]= new QCheckBox("sbndmq2",this);
    box2->addWidget(ArrayCheck[74]);

    ArrayCheck[75]= new QCheckBox("ufndmq2",this);
    box2->addWidget(ArrayCheck[75]);

 //   ArrayCheck[76]= new QCheckBox("sabp",this);
  //  box2->addWidget(ArrayCheck[76]);

 //   ArrayCheck[77]= new QCheckBox("bp2ww",this);
 //   box2->addWidget(ArrayCheck[77]);

//    ArrayCheck[78]= new QCheckBox("bpww2",this);
 //   box2->addWidget(ArrayCheck[78]);

    ArrayCheck[79]= new QCheckBox("kdndm",this);
    box2->addWidget(ArrayCheck[79]);

    ArrayCheck[80]= new QCheckBox("ksa",this);
    box2->addWidget(ArrayCheck[80]);

    ArrayCheck[81]= new QCheckBox("bxs",this);
    box2->addWidget(ArrayCheck[81]);

 //   ArrayCheck[82]= new QCheckBox("fsbndm2 0",this);
 //   box2->addWidget(ArrayCheck[82]);

    ArrayCheck[83]= new QCheckBox("ssecp",this);
    box2->addWidget(ArrayCheck[83]);

    ArrayCheck[84]= new QCheckBox("bsdm",this);
    box2->addWidget(ArrayCheck[84]);

    ArrayCheck[85]= new QCheckBox("epsm",this);
    box2->addWidget(ArrayCheck[85]);




    ui->scrollContents->setLayout(box2);

   QString filename="file.txt";
   QFile file(filename);
   file.open(QIODevice::ReadOnly |QIODevice::Text );
   QTextStream in(&file);
   QString stringa= in.readAll();


   if(stringa.contains("-bf",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-bf")+5,1)=="-"))   { ArrayCheck[0]->click(); }
   if(stringa.contains("-aut",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-aut")+6,1)=="-"))   { ArrayCheck[1]->click(); }
   if(stringa.contains("-mp",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-mp")+5,1)=="-"))   { ArrayCheck[2]->click(); }
   if(stringa.contains("-kmp",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-kmp")+6,1)=="-"))   { ArrayCheck[3]->click(); }
   if(stringa.contains("-bm",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-bm")+5,1)=="-"))   { ArrayCheck[4]->click(); }
   if(stringa.contains("-hor",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-hor")+6,1)=="-"))   { ArrayCheck[5]->click(); }
   if(stringa.contains("-ag",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-ag")+5,1)=="-"))   { ArrayCheck[6]->click(); }
   if(stringa.contains("-kr",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-kr")+5,1)=="-"))   { ArrayCheck[7]->click(); }
   if(stringa.contains("-zt",Qt::CaseSensitive)) { ArrayCheck[8]->click(); }
   if(stringa.contains("-om",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-om")+5,1)=="-"))   { ArrayCheck[9]->click(); }
   if(stringa.contains("-ms",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-ms")+5,1)=="-"))   { ArrayCheck[10]->click(); }
   if(stringa.contains("-qs",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-qs")+5,1)=="-"))   { ArrayCheck[11]->click(); }
   if(stringa.contains("-ac",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-ac")+5,1)=="-"))   { ArrayCheck[12]->click(); }
   if(stringa.contains("-tw",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-tw")+5,1)=="-"))   { ArrayCheck[13]->click(); }
   if(stringa.contains("-tunedbm",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-tunedbm")+10,1)=="-"))   { ArrayCheck[14]->click(); }
   if(stringa.contains("-col",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-col")+6,1)=="-"))   { ArrayCheck[15]->click(); }
   if(stringa.contains("-smith",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-smith")+8,1)=="-"))   { ArrayCheck[16]->click(); }
   if(stringa.contains("-gg",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-gg")+5,1)=="-"))   { ArrayCheck[17]->click(); }
   if(stringa.contains("-raita",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-raita")+8,1)=="-"))   { ArrayCheck[18]->click(); }
   if(stringa.contains("-smoa",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-smoa")+7,1)=="-"))   { ArrayCheck[19]->click(); }
   if(stringa.contains("-rf",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-rf")+4,1)=="-"))   { ArrayCheck[20]->click(); }
   if(stringa.contains("-so",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-so")+5,1)=="-"))   { ArrayCheck[21]->click(); }
   if(stringa.contains("-sa",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-sa")+5,1)=="-"))   { ArrayCheck[22]->click(); }
   if(stringa.contains("-nsn",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-nsn")+6,1)=="-"))   { ArrayCheck[23]->click(); }
   if(stringa.contains("-simon",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-simon")+8,1)=="-"))   { ArrayCheck[24]->click(); }
   if(stringa.contains("-tbm",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-tbm")+6,1)=="-"))   { ArrayCheck[25]->click(); }
   if(stringa.contains("-rcol",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-rcol")+7,1)=="-"))   { ArrayCheck[26]->click(); }
   if(stringa.contains("-trf",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-trf")+6,1)=="-"))   { ArrayCheck[27]->click(); }
   if(stringa.contains("-fdm",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-fdm")+6,1)=="-"))   { ArrayCheck[28]->click(); }
   if(stringa.contains("-bdm",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-bdm")+5,1)=="-"))   { ArrayCheck[29]->click(); }
   if(stringa.contains("-skip",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-skip")+7,1)=="-"))   { ArrayCheck[30]->click(); }
   if(stringa.contains("-askip",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-askip")+8,1)=="-"))   { ArrayCheck[31]->click(); }
   if(stringa.contains("-kmpskip",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-kmpskip")+10,1)=="-"))   { ArrayCheck[32]->click(); }
   if(stringa.contains("-bndml",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-bndml")+8,1)=="-"))   { ArrayCheck[33]->click(); }
   if(stringa.contains("-br",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-br")+5,1)=="-"))   { ArrayCheck[34]->click(); }
   if(stringa.contains("-bom",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-bom")+6,1)=="-"))   { ArrayCheck[35]->click(); }
 //  if(stringa.contains("-bfdm",Qt::CaseSensitive))   { ArrayCheck[36]->click(); }
   if(stringa.contains("-akc",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-akc")+6,1)=="-"))   { ArrayCheck[37]->click(); }
   if(stringa.contains("-fs",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-fs")+5,1)=="-"))   { ArrayCheck[38]->click(); }
//   if(stringa.contains("-sbndm",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-sbndm")+9,1)=="-"))   { ArrayCheck[39]->click(); }
   if(stringa.contains("-tndm",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-tndm")+7,1)=="-"))   { ArrayCheck[40]->click(); }
   if(stringa.contains("-lbndm",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-lbndm")+8,1)=="-"))   { ArrayCheck[41]->click(); }
   if(stringa.contains("-svm0",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-svm0")+7,1)=="-"))   { ArrayCheck[42]->click(); }
   if(stringa.contains("-ffs",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-ffs")+6,1)=="-"))   { ArrayCheck[43]->click(); }
   if(stringa.contains("-bfs",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-bfs")+6,1)=="-"))   { ArrayCheck[44]->click(); }
   if(stringa.contains("-ts",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-ts")+5,1)=="-"))   { ArrayCheck[45]->click(); }
   if(stringa.contains("-ssabs",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-ssabs")+8,1)=="-"))   { ArrayCheck[46]->click(); }
   if(stringa.contains("-ww",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-ww")+5,1)=="-"))   { ArrayCheck[47]->click(); }
   if(stringa.contains("-ldm",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-ldm")+6,1)=="-"))   { ArrayCheck[48]->click(); }
   if(stringa.contains("-bndmq2",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-bndmq2")+9,1)=="-"))   { ArrayCheck[49]->click(); }
   if(stringa.contains("-sbndm2",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-sbndm2")+9,1)=="-"))   { ArrayCheck[50]->click(); }
   if(stringa.contains("-sbndm-bmh",Qt::CaseSensitive) )   { ArrayCheck[51]->click(); }
   if(stringa.contains("-bmh-sbndm",Qt::CaseSensitive) )   { ArrayCheck[52]->click(); }
   if(stringa.contains("-fndm",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-fndm")+7,1)=="-"))   { ArrayCheck[53]->click(); }
   if(stringa.contains("-bww",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-bww")+6,1)=="-"))   { ArrayCheck[54]->click(); }
   if(stringa.contains("-faoso2",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-faoso2")+9,1)=="-"))   { ArrayCheck[55]->click(); }
   if(stringa.contains("-aoso2",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-aoso2")+8,1)=="-"))   { ArrayCheck[56]->click(); }
   if(stringa.contains("-tvsbs",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-tvsbs")+8,1)=="-"))   { ArrayCheck[57]->click(); }
   if(stringa.contains("-pbmh",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-pbmh")+7,1)=="-"))   { ArrayCheck[58]->click(); }
   if(stringa.contains("-ildm1",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-ildm1")+8,1)=="-"))   { ArrayCheck[59]->click(); }
   if(stringa.contains("-ildm2",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-ildm2")+8,1)=="-"))   { ArrayCheck[60]->click(); }
   if(stringa.contains("-fjs",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-fjs")+6,1)=="-"))   { ArrayCheck[61]->click(); }
   if(stringa.contains("-hash3",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-hash3")+8,1)=="-"))   { ArrayCheck[62]->click(); }
   if(stringa.contains("-tsw",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-tsw")+6,1)=="-"))   { ArrayCheck[63]->click(); }
   if(stringa.contains("-blim",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-blim")+7,1)=="-"))   { ArrayCheck[64]->click(); }
   if(stringa.contains("-graspm",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-graspm")+9,1)=="-"))   { ArrayCheck[65]->click(); }
   if(stringa.contains("-ssef",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-ssef")+7,1)=="-"))   { ArrayCheck[66]->click(); }
   if(stringa.contains("-ebom",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-ebom")+7,1)=="-"))   { ArrayCheck[67]->click(); }
   if(stringa.contains("-fbom",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-fbom")+7,1)=="-"))   { ArrayCheck[68]->click(); }
   if(stringa.contains("-sebom",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-sebom")+8,1)=="-"))   { ArrayCheck[69]->click(); }
   if(stringa.contains("-sfbom",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-sfbom")+8,1)=="-"))   { ArrayCheck[70]->click(); }
   if(stringa.contains("-sbdm",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-sbdm")+7,1)=="-"))   { ArrayCheck[71]->click(); }
//   if(stringa.contains("-fsbndm",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-fsdndm")+10,1)=="-"))   { ArrayCheck[72]->click(); }
   if(stringa.contains("-bndmq2",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-bndmq2")+9,1)=="-"))   { ArrayCheck[73]->click(); }
   if(stringa.contains("-sbndmq2",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-sbndmq2")+10,1)=="-"))   { ArrayCheck[74]->click(); }
   if(stringa.contains("-ufndmq2",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-ufndmq2")+10,1)=="-"))   { ArrayCheck[75]->click(); }
//   if(stringa.contains("-sabp",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-sabp")+7,1)=="-"))   { ArrayCheck[76]->click(); }
//   if(stringa.contains("-bp2ww",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-bp2ww")+8,1)=="-"))   { ArrayCheck[77]->click(); }
//   if(stringa.contains("-bpww2",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-bpww2")+8,1)=="-"))   { ArrayCheck[78]->click(); }
   if(stringa.contains("-kbndm",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-kbndm")+8,1)=="-"))   { ArrayCheck[79]->click(); }
   if(stringa.contains("-ksa",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-ksa")+6,1)=="-"))   { ArrayCheck[80]->click(); }
   if(stringa.contains("-bxs",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-bxs")+6,1)=="-"))   { ArrayCheck[81]->click(); }
//   if(stringa.contains("-fsbndm20",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-fsbndm20")+10,1)=="-"))   { ArrayCheck[82]->click(); }
   if(stringa.contains("-ssecp",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-ssecp")+8,1)=="-"))   { ArrayCheck[83]->click(); }
   if(stringa.contains("-bsdm",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-bsdm")+7,1)=="-"))   { ArrayCheck[84]->click(); }
   if(stringa.contains("-epsm",Qt::CaseSensitive) && (stringa.mid(stringa.indexOf("-epsm")+7,1)=="-"))   { ArrayCheck[85]->click(); }




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
