// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShowEvent>
#include "loginwindow.h"
#include "carreraswindow.h"
#include "panelprincipal.h" // Agregar la inclusión del panel principal

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
    void abrirCarreraWindow();
    void setupImages();
    void showEvent(QShowEvent *event) override;
    void mostrarPanelPrincipal(const QString &carreraSeleccionada); // Nuevo slot para mostrar el panel principal

private:
    Ui::MainWindow *ui;
    LoginWindow *loginWindow;
    CarrerasWindow *carreraWindow;
    PanelPrincipal *panelPrincipal; // Agregar un puntero al panel principal
};

#endif // MAINWINDOW_H
