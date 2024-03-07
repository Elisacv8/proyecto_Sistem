#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    // Configurando los tipos de usuario en el QComboBox
    ui->comboBoxTipoUsuario->addItem("IEDD");
    ui->comboBoxTipoUsuario->addItem("Jefes");
    ui->comboBoxTipoUsuario->addItem("Directores");
    ui->comboBoxTipoUsuario->addItem("Decanos");
    ui->comboBoxTipoUsuario->addItem("Consultores");

    // Conectando la señal de clic del botón a la ranura correspondiente
    connect(ui->pushButtonIngresar, &QPushButton::clicked, this, &LoginWindow::on_pushButtonIngresar_clicked);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButtonIngresar_clicked()
{
    // Obtener los valores de los campos de entrada
    QString usuario = ui->lineEditUsuario->text();
    QString contraseña = ui->lineEditPass->text();
    QString correo = ui->lineEditCorreo->text();
    QString tipoUsuario = ui->comboBoxTipoUsuario->currentText();

    // Verificar si algún campo está vacío
    if(usuario.isEmpty() || contraseña.isEmpty() || correo.isEmpty()) {
        QMessageBox::warning(this, "Error", "Por favor, complete todos los campos.");
        return;
    }

    // Si todos los campos están completos, emitir la señal ingresarClicked()
    emit ingresarClicked();
}
