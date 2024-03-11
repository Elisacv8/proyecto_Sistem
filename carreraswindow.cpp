// carreraswindow.cpp
#include "carreraswindow.h"
#include "ui_carreraswindow.h"

CarrerasWindow::CarrerasWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CarrerasWindow)
{
    ui->setupUi(this);

    // Configurar carreras y nombre de facultad
    configurarCarreras();

    // Conectando la señal de clic del botón a la ranura correspondiente
    connect(ui->pushButtonVolver, &QPushButton::clicked, this, &CarrerasWindow::volver);
    connect(ui->listWidgetCarrera, &QListWidget::itemClicked, this, &CarrerasWindow::onCarreraSeleccionada); // Conexión para manejar la selección de la carrera
    connect(ui->listWidgetCarreras, &QListWidget::itemClicked, this, &CarrerasWindow::onCarreraSeleccionada); // Conexión para manejar la selección de la carrera
    connect(ui->listWidgetCarreras_2, &QListWidget::itemClicked, this, &CarrerasWindow::onCarreraSeleccionada); // Conexión para manejar la selección de la carrera
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

void CarrerasWindow::onCarreraSeleccionada(QListWidgetItem *item)
{
    QString nombreCarrera = item->text();
    emit carreraSeleccionada(nombreCarrera); // Emitir la señal con el nombre de la carrera seleccionada
}

void CarrerasWindow::cargarArchivo()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Abrir archivo"), QDir::homePath(), tr("Archivos de texto (*.txt);;Todos los archivos (*.*)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Limpiar el widget antes de cargar el nuevo archivo
            //.ui->tableWidget->clear(); // Cambiar a un nuevo QListWidget o QTableWidget

            // Leer el archivo línea por línea y agregar los datos al widget
            QTextStream in(&file);
            int row = 0;
            while (!in.atEnd()) {
                QString line = in.readLine();
                QStringList fields = line.split('\t'); // Suponiendo que el archivo está separado por tabulaciones
                foreach(const QString &field, fields) {
                    // Agregar cada campo como un nuevo elemento en el widget
                   // ui->nuevoListWidget->addItem(field); // Cambiar a un nuevo QListWidget o QTableWidget
                }
                row++;
            }
            file.close();
        } else {
            QMessageBox::critical(this, tr("Error"), tr("No se pudo abrir el archivo."));
        }
    }
}
