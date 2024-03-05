#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShowEvent> // Necesario para QShowEvent
#include "loginwindow.h"
#include "carreraswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();
    void abrirCarreraWindow(); // Método para abrir la ventana de carreras
    void setupImages(); // Método para configurar las imágenes
    void showEvent(QShowEvent *event) override; // Sobreescribir el evento de mostrar

private:
    Ui::MainWindow *ui;
    LoginWindow *loginWindow;
    CarrerasWindow *carreraWindow; // Agregamos un puntero a CarrerasWindow
};

#endif // MAINWINDOW_H
