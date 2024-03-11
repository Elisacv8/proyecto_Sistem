// carreraswindow.h
#ifndef CARRERASWINDOW_H
#define CARRERASWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTableWidgetItem> // Agregar la inclusión del encabezado QTableWidgetItem

QT_BEGIN_NAMESPACE
namespace Ui { class CarrerasWindow; }
QT_END_NAMESPACE

class CarrerasWindow : public QMainWindow
{
    Q_OBJECT

public:
    CarrerasWindow(QWidget *parent = nullptr);
    ~CarrerasWindow();

signals:
    void volverClicked();
    void carreraSeleccionada(const QString &nombreCarrera); // Nueva señal para enviar la carrera seleccionada

private slots:
    void volver(); // Método para volver al inicio
    void onCarreraSeleccionada(QListWidgetItem *item); // Nuevo slot para manejar la selección de la carrera
    void cargarArchivo();

private:
    Ui::CarrerasWindow *ui;

    void configurarCarreras();
};

#endif // CARRERASWINDOW_H
