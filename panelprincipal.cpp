#include "panelprincipal.h"
#include "ui_panelprincipal.h"

PanelPrincipal::PanelPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PanelPrincipal)
{
    ui->setupUi(this);
}

PanelPrincipal::~PanelPrincipal()
{
    delete ui;
}
