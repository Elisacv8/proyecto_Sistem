#ifndef CARRERASWINDOW_H
#define CARRERASWINDOW_H

#include <QMainWindow>

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

private slots:
    void volver();

private:
    Ui::CarrerasWindow *ui;

    void configurarCarreras();
};

#endif // CARRERASWINDOW_H
