#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    updateDotFile();
    updateImage();
    renderImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDotFile()
{
    std::ofstream myFile;
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    myFile.open
    (
        "file.dot"
    );

    std::string textToFile;
    if (ui->radioButtonTrad->isChecked())
        textToFile = redBlackTree.gitDotFileMode1();
    else
        textToFile = redBlackTree.gitDotFileMode2();

    myFile << textToFile;
    myFile.close();
}

void MainWindow::updateImage()
{
    std::string message =
                "dot -Tpng file.dot > file.png";
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    system(message.c_str());
}

void MainWindow::renderImage()
{
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    QPixmap image("file.png");
    ui->labelOfImage->setPixmap(image);
    ui->labelOfImage->show();
}

template <class Container>
void MainWindow::split3(const std::string& str, Container& cont,
              char delim)
{
    std::size_t current, previous = 0;
    current = str.find(delim);
    while (current != std::string::npos)
    {
        cont.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delim, previous);
    }
    cont.push_back(str.substr(previous, current - previous));
}

void MainWindow::on_pushButtonOfInsert_clicked()
{
    std::vector<std::string> numbersAsString;
    std::string numbers = ui->lineEditOfInsert->text().toStdString();
    split3(numbers, numbersAsString);

    bool ret;
    for (auto numberAsStr: numbersAsString)
    {
        int number = std::atoi(numberAsStr.c_str());
        ret = redBlackTree.insertInterface(number);

        QMessageBox msgBox;
        if (ret)
            msgBox.setText("The number "+QString::number(number)+" was inserted");
        else
            msgBox.setText("This number already exists in the tree");
        msgBox.exec();
    }

    updateDotFile();
    updateImage();
    renderImage();
}

void MainWindow::on_pushButtonOfSearch_clicked()
{
    int toSearch = ui->lineEditOfSearch->text().toInt();
    bool ret = redBlackTree.search(toSearch);

    QMessageBox msgBox;

    if (ret)
        msgBox.setText("This number exists");
    else
        msgBox.setText("This number does not exists");

    msgBox.exec();
}

void MainWindow::on_pushButtonOfRemove_clicked()
{
    int toRemove = ui->lineEditOfRemove->text().toInt();
    NodeOfRedBlackTree *node = redBlackTree.removeInterface(toRemove);

    updateDotFile();
    updateImage();
    renderImage();

    if (node != nullptr)
        delete node;
}

void MainWindow::on_pushButtonPreOrdem_clicked()
{
    //Eu, esq, direita

    std::string ret = redBlackTree.preOrder();
    QMessageBox msgBox;
    msgBox.setText(ret.c_str());
    msgBox.exec();
}

void MainWindow::on_pushButtonEmOrdem_clicked()
{
    //esq, eu, dir

    std::string ret = redBlackTree.inOrder();
    QMessageBox msgBox;
    msgBox.setText(ret.c_str());
    msgBox.exec();
}

void MainWindow::on_pushButtonPosOrdem_clicked()
{
    //esq, dir, eu

    std::string ret = redBlackTree.posOrder();
    QMessageBox msgBox;
    msgBox.setText(ret.c_str());
    msgBox.exec();
}

void MainWindow::on_pushButtonEmNivel_clicked()
{
    //eu, filhos, netos, bisnetos

    std::string ret = redBlackTree.InLevelOrder();
    QMessageBox msgBox;
    msgBox.setText(ret.c_str());
    msgBox.exec();
}

void MainWindow::on_radioButtonTrad_toggled(bool checked)
{
    updateDotFile();
    updateImage();
    renderImage();
}

void MainWindow::on_pushButtonChangeColor_clicked()
{
    std::vector<std::string> colorAsString;
    std::string colors = ui->lineEditOfColors->text().toStdString();
    split3(colors, colorAsString);

    std::vector<Color> vectorOfColors;

    for (auto colorAsStr: colorAsString)
    {
        if
        (
            colorAsStr.compare("r") == 0 ||
            colorAsStr.compare("R") == 0 ||
            colorAsStr.compare("red") == 0 ||
            colorAsStr.compare("RED") == 0
        )
        {
            vectorOfColors.push_back(Color::RED);
        }
        else
        {
            vectorOfColors.push_back(Color::BLACK);
        }
    }

    std::vector<NodeOfRedBlackTree*> nodes = redBlackTree.inLevelOrderNodes();
    for (int index = 0; index < nodes.size() && index < vectorOfColors.size(); ++index)
    {
        nodes.at(index)->color = vectorOfColors.at(index);
    }

    updateDotFile();
    updateImage();
    renderImage();
}
