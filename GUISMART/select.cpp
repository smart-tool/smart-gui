#include "select.h"
#include "ui_select.h"
#include <QVBoxLayout>
#include <QCheckBox>
#include <fstream>
#include <iostream>

 QCheckBox** ArrayCheck= new QCheckBox*[86];

Selezione::Selezione(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Selezione)
{
    ui->setupUi(this);

    QVBoxLayout* box2= new QVBoxLayout(this);





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



    //  ArrayCheck[0]->add
}
