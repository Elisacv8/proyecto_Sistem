#include "carreraswindow.h"
#include "ui_carreraswindow.h"

CarrerasWindow::CarrerasWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CarrerasWindow)
{
    ui->setupUi(this);

    // Configurar carreras y nombre de facultad
    configurarCarreras();

    // Conectando la señal de clic del botón a la ranura correspondiente
    connect(ui->pushButtonVolver, &QPushButton::clicked, this, &CarrerasWindow::volver);
}

CarrerasWindow::~CarrerasWindow()
{
    delete ui;
}

void CarrerasWindow::volver()
{
    // Emitir la señal para volver a la ventana principal
    emit volverClicked();
}

void CarrerasWindow::configurarCarreras()
{
    // Nombre de la facultad
    ui->labelFacultad1->setText("Facultad de Ciencias Administrativas y Sociales");
    ui->labelFacultad2_2->setText("Facultad de Ingeniería");
    ui->labelFacultad3->setText("Escuela de Arte y Diseño");

    // Carreras
    QStringList carrerasAdministrativas = {
        "Licenciatura En Administración De La Hospitalidad Y El Turismo",
        "Licenciatura en Administración Industrial e Inteligencia de Negocios",
        "Licenciatura en Administración Industrial y Emprendimiento",
        "Licenciatura en Administración Industrial y Operaciones",
        "Licenciatura En Derecho",
        "Licenciatura En Finanzas y Economía",
        "Licenciatura En Mercadotecnia Y Negocios Internacionales",
        "Licenciatura En Relaciones Internacionales"
    };
    QStringList carrerasIngenieria = {
        "Ingenieria En Biomédica",
        "Ingenieria En Ciencia De Datos E Inteligencia Artificial",
        "Ingenieria Civil",
        "Ingenieria En Energia",
        "Ingenieria Industrial Y De Sistemas",
        "Ingenieria En Mecatronica",
        "Ingenieria En Sistemas Computacionales",
        "Ingenieria En Telecomunicaciones Y Electronica"
    };
    QStringList carrerasArteyDiseno = {
        "Licenciatura En Animación Digital Y Diseño Interactivo",
        "Arquitectura",
        "Licenciatura En Comunicación Audiovisual Y Publicitaria",
        "Licenciatura En Diseño De Modas",
        "Licenciatura En Diseño Gráfico",
        "Licenciatura En Gastronomía"
    };

    // Agregar carreras a QListWidget
    ui->listWidgetCarrera->addItems(carrerasAdministrativas);
    ui->listWidgetCarreras->addItems(carrerasIngenieria);
    ui->listWidgetCarreras_2->addItems(carrerasArteyDiseno);
}
