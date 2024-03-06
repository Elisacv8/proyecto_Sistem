#ifndef PANELPRINCIPAL_H
#define PANELPRINCIPAL_H

#include <QMainWindow>

namespace Ui {
class PanelPrincipal;
}

class PanelPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit PanelPrincipal(QWidget *parent = nullptr);
    ~PanelPrincipal();

private:
    Ui::PanelPrincipal *ui;
};

#endif // PANELPRINCIPAL_H
