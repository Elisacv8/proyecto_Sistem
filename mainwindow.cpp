#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loginWindow = new LoginWindow(this);
    carreraWindow = new CarrerasWindow(this); // Inicializamos carreraWindow

    connect(loginWindow, &LoginWindow::ingresarClicked, this, &MainWindow::abrirCarreraWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    loginWindow->show();
    this->hide(); // Ocultar la ventana principal al mostrar la ventana de inicio de sesión
}

void MainWindow::abrirCarreraWindow()
{
    // Mostrar la ventana de carreras
    carreraWindow->show();
    loginWindow->hide(); // Ocultar la ventana de inicio de sesión al mostrar la ventana de carreras
}

void MainWindow::setupImages() {
    QPixmap image(":/images/image1.jpg");
    ui->imageLabel->setPixmap(image.scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));

    QPixmap image2(":/images/image2.jpg");
    ui->imageLabel2->setPixmap(image2.scaled(ui->imageLabel2->size(), Qt::KeepAspectRatio));
}

void MainWindow::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
    setupImages();
}
