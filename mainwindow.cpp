// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loginWindow = new LoginWindow(this);
    carreraWindow = new CarrerasWindow(this);
    panelPrincipal = new PanelPrincipal(this); // Inicializar el panel principal

    connect(loginWindow, &LoginWindow::ingresarClicked, this, &MainWindow::abrirCarreraWindow);
    connect(carreraWindow, &CarrerasWindow::carreraSeleccionada, this, &MainWindow::mostrarPanelPrincipal); // Conexión para mostrar el panel principal
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
    ui->imageLabel->setPixmap(image2.scaled(ui->imageLabel->size(), Qt::KeepAspectRatio)); // Cambiar de imageLabel2 a imageLabel
}

void MainWindow::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
    setupImages();
}

void MainWindow::mostrarPanelPrincipal(const QString &carreraSeleccionada)
{
    panelPrincipal->show(); // Mostrar el panel principal
    carreraWindow->hide(); // Ocultar la ventana de carreras
}
