#include "select.h"
#include "ui_select.h"
#include <QVBoxLayout>
#include <QCheckBox>

Selezione::Selezione(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Selezione)
{
    ui->setupUi(this);

    QVBoxLayout* box2= new QVBoxLayout(this);

   QCheckBox** ArrayCheck= new QCheckBox*[5];




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

    ArrayCheck[0]= new QCheckBox("om",this);
    box2->addWidget(ArrayCheck[0]);

    ArrayCheck[0]= new QCheckBox("ms",this);
    box2->addWidget(ArrayCheck[0]);

    ArrayCheck[]= new QCheckBox("qs",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("ac",this);
    box2->addWidget(ArrayCheck[]);


    ArrayCheck[]= new QCheckBox("tw",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("tunedbm",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("col",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("smith",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("gg",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("raita",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("smoa",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("rf",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("so",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("sa",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("nsn",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("simon",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("tbm",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("rcol",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("trf",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("fdm",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("bdm",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("skip",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("askip",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("kmpskip",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("bndml",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("br",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("bom",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("dfdm",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("akc",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("fs",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("sdndm",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("tndm",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("lbndm",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("svm0",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("ffs",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("bfs",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("ts",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("ssabs",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("ww",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("ldm",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("bndmq2",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("sdndm2",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("sbndm-bmh",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("bmh-sdndm",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("fndm",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("bww",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("faoso2",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("aoso2",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("tvsbs",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("pbmh",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("ildm1",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("ildm2",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("fjs",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("hash3",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("tsw",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("blim",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("graspm",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("ssef",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("ebom",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("fbom",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("sebom",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("sfbom",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("sdbm",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("fsdbdm",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("bndmq2",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("sbndmq2",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("ufndmq2",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("sabp",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("bp2ww",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("bpww2",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("kdndm",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("ksa",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("bxs",this);
    box2->addWidget(ArrayCheck[]);


    ArrayCheck[]= new QCheckBox("fsbndm2 0",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("ssecp",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("bsdm",this);
    box2->addWidget(ArrayCheck[]);

    ArrayCheck[]= new QCheckBox("epsm",this);
    box2->addWidget(ArrayCheck[]);






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
