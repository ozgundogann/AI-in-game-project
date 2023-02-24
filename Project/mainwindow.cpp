#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    textBrowser = new QTextBrowser();
    textBrowser->setFont(QFont("Stencil",12));
    textBrowser->setAlignment(Qt::AlignCenter);
    textBrowser->append("Detective has found that...\n\n");
    textBrowser->hide();
    ui->resultLabel->hide();
    ui->nextDayButton->hide();
    ui->dayLabel->hide();
    ui->dayNumber->hide();

    ui->imageLabel->setPixmap(QPixmap(":/Characters/Sources/Characters/allCharacterss.jpg"));
    agent = new Detective;

    detectiveInfo = new QMessageBox("Detective's Turn","Detective is searching...\n\n\n"
                                    "Midnight, everyone is asleep.\nThe detective started looking for the murderer.",
                                    QMessageBox::NoIcon,QMessageBox::Ok | QMessageBox::Default,
                                    QMessageBox::NoButton,QMessageBox::NoButton);

    detectiveInfo->setFont(QFont("Stencil",14));
    detectiveInfo->setIconPixmap(QPixmap (":/Characters/Sources/Characters/detective.png").scaledToWidth(100));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete agent;
}

void MainWindow::on_nextDayButton_clicked()
{
    bool flag = true;
    for (int i = 0; i < personNumber; ++i) {
        if(person[i]->radioButton->isChecked()){
            person[i]->setPoint(-100);

            person[i]->radioButton->setAutoExclusive(false);
            person[i]->radioButton->setEnabled(false);
            person[i]->radioButton->setChecked(false);
            person[i]->label->setPixmap(QPixmap(":/Characters/Sources/Characters/Normal_Man_Dead100x150.png"));
            flag = false;
            break;
        }
    }
    if(flag){
        QMessageBox::critical(this,"Invalid","You must choose someone");
        return;
    }
    detectiveInfo->exec();
    ui->dayNumber->setText(QString::number(++killCount));
    if(killCount == personNumber - 2){
        ui->resultLabel->setText("YOU WON");
        for (int i = 0; i < personNumber; ++i) {
            ui->nextDayButton->hide();
            person[i]->radioButton->setEnabled(false);
        }

        winPixes();
        return;
    }

    while(person[x]->getPoint() < 0)
        x = QRandomGenerator::global()->bounded(0,personNumber);


    agent->examine(person[x],x);
    if(agent->conclude(x)){
        //ui->textBrowser->append(person[x]->name + " was a " + agent->knowledgeBase[x]->profession);
        textBrowser->append("-> " + person[x]->name + " was a " + agent->knowledgeBase[x]->profession);
        if(agent->knowledgeBase[x]->profession == "Murderer"){
            ui->resultLabel->setText("Detective has found you... YOU LOST!");
            for (int i = 0; i < personNumber; ++i) {
                ui->nextDayButton->hide();
                person[i]->radioButton->setEnabled(false);
            }

            winPixes();
            return;
        }
    }
}
void MainWindow::on_pNumButton_clicked()
{
    QFile file(":/Sources/Sources/names.txt");
    QString line;
    QStringList word;
    int random;
    int randomArr[4];
    QString names[4];

    ui->gameNameLabel->hide();
    ui->playerLabel->hide();
    ui->pNumButton->hide();
    ui->comboBox->hide();
    ui->imageLabel->hide();
    ui->dayLabel->show();
    ui->dayNumber->show();
    ui->nextDayButton->show();

    personNumber = ui->comboBox->currentText().toInt();
    x = QRandomGenerator::global()->bounded(0,personNumber);


    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        for (int i = 0; i < personNumber; ++i){
            line = in.readLine();
            word = line.split('-');
            if( line != ""){
                if(word[1] == "Builder")
                    person[i] = new Builder;
                else if(word[1] == "Farmer")
                    person[i] = new Farmer;
                else if (word[1] == "Hunter")
                    person[i] = new Hunter;

                person[i]->name = word[0];
                person[i]->radioButton->setText(person[i]->name);
            }
            else
                i--;
        }
     }
    else
        QMessageBox::warning(0, "Error", "Could not open the file!");

    file.close();

    for(int i = 0; i < 4 ; i++){
        random = QRandomGenerator::global()->bounded(0,personNumber);
        for(int j = 0; j < i; j++){
            if(randomArr[j] == random){
                random = QRandomGenerator::global()->bounded(0,personNumber);
                j = -1;
            }
        }
        randomArr[i] = random;
        names[i] = person[randomArr[i]]->name;
    }

    delete person[randomArr[0]];
    person[randomArr[0]] = new Murderer;
    person[randomArr[0]]->name = names[0];
    person[randomArr[0]]->radioButton->setText(person[randomArr[0]]->name + " (YOU)\nMurderer");

    delete person[randomArr[1]];
    person[randomArr[1]] = new Doctor;
    person[randomArr[1]]->name = names[1];
    person[randomArr[1]]->radioButton->setText(person[randomArr[1]]->name);

    delete person[randomArr[2]];
    person[randomArr[2]] = new Butcher;
    person[randomArr[2]]->name = names[2];
    person[randomArr[2]]->radioButton->setText(person[randomArr[2]]->name);

    delete person[randomArr[3]];
    person[randomArr[3]] = new Mayor;
    person[randomArr[3]]->name = names[3];
    person[randomArr[3]]->radioButton->setText(person[randomArr[3]]->name);


    for (int i = 0; i < personNumber; ++i) {
        person[i]->radioButton->setStyleSheet("QRadioButton"
                                              "{"
                                              "font : 15px Stencil;"
                                              "}");
        person[i]->label->setPixmap(QPixmap(":/Characters/Sources/Characters/Normal_Man100x150.png"));

    }
    person[randomArr[0]]->label->setPixmap(QPixmap(":/Characters/Sources/Characters/murderer100x150.png"));

    int row=-1,column=0, y = 5;

    while(personNumber % y != 0)
        y--;

    for (int i = 0; i < personNumber; ++i) {
        box[i] = new QVBoxLayout;
        box[i]->addWidget(person[i]->label);
        box[i]->addWidget(person[i]->radioButton);
        column = i;
        if(column % y == 0)
            row++;
        ui->gridLayout->addLayout(box[i],row,column % y);
    }

}

void MainWindow::winPixes(){
    textBrowser->show();
    ui->resultLabel->show();
    for (int i = 0; i < personNumber; ++i) {

        if(person[i]->profession == "Doctor")
            person[i]->label->setPixmap(QPixmap(":/Characters/Sources/Characters/doctor100x150.png"));

        else if(person[i]->profession == "Butcher")
            person[i]->label->setPixmap(QPixmap(":/Characters/Sources/Characters/butcher100x150.png"));

        else if(person[i]->profession == "Builder")
            person[i]->label->setPixmap(QPixmap(":/Characters/Sources/Characters/builder100x150.png"));

        else if(person[i]->profession == "Farmer")
            person[i]->label->setPixmap(QPixmap(":/Characters/Sources/Characters/farmer100x150.png"));

        else if(person[i]->profession == "Hunter")
            person[i]->label->setPixmap(QPixmap(":/Characters/Sources/Characters/hunter100x150.png"));

        else if(person[i]->profession == "Mayor")
            person[i]->label->setPixmap(QPixmap(":/Characters/Sources/Characters/mayor100x150.png"));
    }
}

