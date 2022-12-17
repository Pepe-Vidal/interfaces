#include "editor.h"
#include <QMenuBar>
#include <QToolBar>
#include <QTextDocument>
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QIODevice>
#include <QTextBlock>
#include <QCloseEvent>
#include <QAction>
#include <QFileInfo>
#include <QObject>
#include <QVariant>
#include <QStatusBar>


Editor::Editor(QWidget *parent) : QMainWindow(parent)
{

	resize(800, 600);

	listaRutas = new QStringList();

	editorCentral = new QTextEdit();
	dBuscar = NULL;
	dInfo = NULL;
	dExamen = NULL;
	
	recargar = new QPushButton("Recargar");
	
	connect(recargar, SIGNAL(clicked()),
		this, SLOT(slotCargarFichero()));
		
	
	crearBarraStado();
	hacerMenus();
	
	
	setCentralWidget(editorCentral);

	setWindowIcon(QIcon("img/contact-book.png"));

	connect(editorCentral, SIGNAL(textChanged()),
		   this, SLOT(slotModificado()));
		   

	recargar = new QPushButton("Recargar");
	
	connect(recargar, SIGNAL(clicked()),
		this, SLOT(slotCargarFichero()));
	
	modificado = false;
	rutaActual.clear();
	

	
	qDebug() << "33" << modificado;
}

void Editor::hacerMenus()
{
	menuArchivo = new QMenu("Archivo");

	QMenuBar *barra = menuBar();
	barra->addMenu(menuArchivo);

	accionSalir = new QAction("Salir");
	accionSalir->setIcon(QIcon("img/cancel.png"));
	accionSalir->setShortcut(QKeySequence::Quit);
	accionSalir->setStatusTip("Salir del programa");

	accionNuevo = new QAction("Nuevo");
	accionNuevo->setIcon(QIcon("img/add-button.png"));
	accionNuevo->setShortcut(QKeySequence::New);
	accionNuevo->setStatusTip("Crear un fichero");

	accionAbrir = new QAction("Abrir");
	accionAbrir->setIcon(QIcon("img/add-file.png"));
	accionAbrir->setShortcut(QKeySequence::Open);
	accionAbrir->setStatusTip("Abrir fichero");

	accionGuardar = new QAction("Guardar");
	accionGuardar->setIcon(QIcon("img/save-file.png"));
	accionGuardar->setShortcut(QKeySequence::Save);
	accionGuardar->setStatusTip("Guardar fichero");

	accionGuardarComo = new QAction("Guardar Como");
	accionGuardarComo->setIcon(QIcon("img/save-file-as.png"));
	accionGuardarComo->setShortcut(QKeySequence::SaveAs);
	accionGuardarComo->setStatusTip("Guardar Como");
	
	
	connect(accionSalir, SIGNAL(triggered()),
		   this, SLOT(slotSalir()));

	connect(accionNuevo, SIGNAL(triggered()),
		   this, SLOT(slotNuevoFichero()));

	connect(accionAbrir, SIGNAL(triggered()),
		   this, SLOT(slotAbrir()));

	connect(accionGuardar, SIGNAL(triggered()),
		   this, SLOT(slotGuardar()));

	connect(accionGuardarComo, SIGNAL(triggered()),
		   this, SLOT(slotGuardarComo()));

	menuArchivo->addAction(accionSalir);
	menuArchivo->addAction(accionNuevo);
	menuArchivo->addAction(accionAbrir);
	menuArchivo->addAction(accionGuardar);
	menuArchivo->addAction(accionGuardarComo);


	editorCentral->addAction(accionNuevo);
	editorCentral->addAction(accionAbrir);
	editorCentral->addAction(accionGuardar);
	editorCentral->addAction(accionGuardarComo);


	editorCentral->setContextMenuPolicy(Qt::ActionsContextMenu);

	barraHerramientas = new QToolBar();

	barraHerramientas->addAction(accionSalir);
	barraHerramientas->addAction(accionNuevo);
	barraHerramientas->addAction(accionAbrir);
	barraHerramientas->addAction(accionGuardar);
	barraHerramientas->addAction(accionGuardarComo);
	
	menuArchivo->addSeparator();
	
	menuEditar = new QMenu("Editar");
	barra->addMenu(menuEditar);
	
	accionBuscar = new QAction("Buscar");
	accionBuscar->setShortcut(QKeySequence::Find);
	accionBuscar->setStatusTip("Buscar");
	
	connect(accionBuscar, SIGNAL(triggered()),
		   this, SLOT(slotBuscar()));
		   
	accionInfo = new QAction("Info");
	
	connect(accionInfo, SIGNAL(triggered()),
		   this, SLOT(slotInfo()));
		   
	menuEditar->addAction(accionBuscar);
	menuEditar->addAction(accionInfo);
	
	
	menuExamen = new QMenu("Examen");
	barra->addMenu(menuExamen);
	
	accionExamen = new QAction("Examen");
	accionExamen->setStatusTip("Examen");
	
	connect(accionExamen, SIGNAL(triggered()),
		   this, SLOT(slotExamen()));
	
	menuExamen->addAction(accionExamen);
	
	

	addToolBar(barraHerramientas);
}

// ************************ SLOTS ****************************

void Editor::crearBarraStado(){

lEsNombreArchivo=  new QLabel("");
lEsArchivoModificado = new QLabel("");

//QFileInfo(rutaActual).fileName();

barraEstado = statusBar();
barraEstado->addWidget(lEsNombreArchivo);
barraEstado->addWidget(lEsArchivoModificado);


}
void Editor::slotExamen(){

//QTextDocument *doc = editorCentral->document();

	if(dExamen == NULL){
		dExamen = new DExamen(listaRutas);
		
		connect(dExamen, SIGNAL(senyalCargarFile(QString)),
		  this, SLOT(slotCargarFichero(QString)));

		}
		
	dExamen->show();
}
void Editor::slotCargarFichero(QString ruta){

abrirArchivo(ruta);

}
void Editor::slotCargarFichero( ){

abrirArchivo(rutaActual);

}

void Editor::slotInfo(){

QTextDocument *doc = editorCentral->document();

	if(dInfo == NULL){
		dInfo = new DInfo(doc);
		
		connect(editorCentral, SIGNAL(textChanged()),
		   dInfo, SLOT(slotTextoModificado()));

		}
		
	dInfo->show();
}

void Editor::slotBuscar()
{

	if(dBuscar == NULL){
		dBuscar = new DBuscar();

	connect(dBuscar, SIGNAL(senyalBotonBuscarAlante(QString)),
		   this, SLOT(slotBuscarPalabra(QString)));

		}
		
	dBuscar->show();

}

void Editor::slotBuscarPalabra(QString palabra)
{

qDebug() << palabra;

qDebug() << editorCentral->find(palabra,QTextDocument::FindBackward);

}

void Editor::slotSalir()
{

	if (!quieresContinuar())
	{
		return;
	}
	close();
}
void Editor::slotNuevoFichero()
{

	if (!quieresContinuar())
	{
		return;
	}

	QTextDocument *doc = editorCentral->document();
	doc->clear();

	modificado = false;
	barraEstado->removeWidget(recargar);
	lEsArchivoModificado->setText("");
	rutaActual.clear();
	lEsNombreArchivo->setText("");
}

void Editor::slotAbrir()
{

	if (!quieresContinuar())
	{
		return;
	}

	QString ruta = QFileDialog::getOpenFileName(this, QString("Abrir Archivo"), ".", QString("Fichero de texto (*.txt *.cpp *.h)"));

	if (ruta.isEmpty())
	{
		return;
	}

	abrirArchivo(ruta);
	addArchivoMenu(ruta);
}

void Editor::addArchivoMenu(QString rutaNew){

		
	for(int i = 0 ; i< acciones.size(); i++ ){
		menuArchivo->removeAction(acciones.at(i));
	}
		
	for(int i = 0 ; i< acciones.size(); i++ ){
		delete acciones.at(i);
	}
	
	acciones.clear();
	
	listaRutas->removeAll(rutaNew);
	listaRutas->prepend(rutaNew);
	
	if(dExamen != NULL){

		dExamen->cargarFile(listaRutas);
	}
	
	
	for(int i = 0 ; i< listaRutas->size(); i++ ){
		
		QString ruta = listaRutas->at(i);
	
		QString rutaCorta = QFileInfo(ruta).fileName();
		QAction *accion = new QAction(rutaCorta);
		
		QVariant vaRuta(ruta);
		accion->setData(vaRuta);
		
		connect(accion, SIGNAL(triggered()),
		   	this, SLOT(slotAbrirReciente()));
		   	
		acciones.append(accion);
		menuArchivo->addAction(accion);
	
	}
	

}
void Editor::slotAbrirReciente(){

	if (!quieresContinuar())
	{
		return;
	}
	
	QObject * oEmisor = sender();
	QAction *accionCulpable = qobject_cast<QAction*>(oEmisor);

	//QVariant vaRuta = accionCulpable->data();
	//QString ruta = vaRuta.toString() ;
	
	//QVariant vaRuta = accionCulpable->data();
	QString ruta = accionCulpable->data().toString() ;
	
	qDebug() << "hola " << accionCulpable->text() << ruta ;
	
	abrirArchivo(ruta);
}

bool Editor::slotGuardar()
{

	if (rutaActual.isEmpty())
	{
		return slotGuardarComo();
	}
	else
	{
		return guardarArchivo(rutaActual);
	}
}

bool Editor::slotGuardarComo()
{

	QString ruta = QFileDialog::getSaveFileName(this,
									    tr("Guardar Como"), ".",
									    tr("Texto (*.txt *.doc *.info *.cpp *.h)"));

	if (ruta.isEmpty())
	{
		return false;
	}

	return guardarArchivo(ruta);


}

void Editor::slotModificado()
{

qDebug()<< modificado;

	modificado = true;
	barraEstado->addWidget(recargar);
	recargar->show();
	lEsArchivoModificado->setText("modificado");
qDebug() << modificado;
}

// ************* Metodos *************
bool Editor::guardarArchivo(QString rutaFichero)
{

	QFile fichero(rutaFichero);

	if (!fichero.open(QIODevice::WriteOnly))
	{
		QMessageBox::warning(this, tr("Editor"),
						 tr("Cannot read file %1:\n%2.")
							.arg(fichero.fileName())
							.arg(fichero.errorString()));
		return false;
	}

	QTextStream stream(&fichero);

	for (int i = 0; i < editorCentral->document()->blockCount(); i++)
	{
		stream << editorCentral->document()->findBlockByNumber(i).text() << Qt::endl;
	}
	rutaActual = rutaFichero;
	modificado = false;
	barraEstado->removeWidget(recargar);
	lEsArchivoModificado->setText("");
	QString rutac=QFileInfo(rutaActual).fileName();
	lEsNombreArchivo->setText(rutac);
	
	addArchivoMenu(rutaFichero);
	
	return true;
}
void Editor::abrirArchivo(QString rutaFichero)
{
	QTextDocument *doc = editorCentral->document();
	doc->clear();

	QFile fichero(rutaFichero);

	if (!fichero.open(QIODevice::ReadOnly))
	{
		QMessageBox::warning(this, tr("Editor"),
						 tr("Cannot read file %1:\n%2.")
							.arg(fichero.fileName())
							.arg(fichero.errorString()));
		return;
	}

	QTextStream stream(&fichero);

	while (!stream.atEnd())
	{
		editorCentral->append(stream.readLine());
	}

	modificado = false;
	barraEstado->removeWidget(recargar);
	lEsArchivoModificado->setText("");
	rutaActual = rutaFichero;
	addArchivoMenu( rutaFichero);
	QString rutac=QFileInfo(rutaActual).fileName();
	lEsNombreArchivo->setText(rutac);
}
bool Editor::quieresContinuar()
{
	if (modificado)
	{
		int respuesta = QMessageBox::warning(this, QString("Guardar"),
									  QString("Quieres guardar el documento actual."),
									  QMessageBox::Save | QMessageBox::No | QMessageBox::Cancel);

		if (respuesta == QMessageBox::Save)
		{ // veamos si el usuario quiere guardar
			if (slotGuardar()){
			return true;
			}else{
			QMessageBox::warning(this, QString("ERROR"),
									  QString("El archivo no se pudo guardar"),
									  QMessageBox::Close);
			
			return false;
			}
			
		}
		else if (respuesta == QMessageBox::Cancel) // el usuario no quiere seguir
			return false;
		/* else */
		return true; // el usuario ha pulsado "NO guardar" quiere salir YA

	} // no había modificaciones
	return true;
}
void Editor::closeEvent(QCloseEvent *event)
{
 
	if (quieresContinuar())
	{
		event->accept();
	} else {
		event->ignore();    	
	}
	qDebug() << "intentando salir";
}
