#ifndef _EDITOR_H
#define _EDITOR_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>
#include <QVector>
#include <QStringList>
#include <QPushButton>

#include "dbuscar.h"
#include "dinfo.h"
#include "dexamen.h"

class Editor : public QMainWindow
{

	Q_OBJECT

public:
	Editor(QWidget *parent = nullptr);

	bool modificado;
	
	QStatusBar *barraEstado;
	QPushButton *recargar;
	QString rutaActual;
	QLabel *lEsNombreArchivo;
	QLabel *lEsArchivoModificado;
	QStringList *listaRutas;
	QTextEdit *editorCentral;
	QMenu *menuArchivo;
	QMenu *menuEditar;
	QMenu *menuExamen;
	QToolBar *barraHerramientas;
	QAction *accionBuscar;
	QAction *accionExamen;
	QAction *accionInfo;
	QAction *accionSalir;
	QAction *accionNuevo;
	QAction *accionAbrir;
	QAction *accionGuardar;
	QAction *accionGuardarComo;
	QVector<QAction*> acciones;
	
	DBuscar *dBuscar;
	DInfo *dInfo;
	DExamen *dExamen;

	/*
	QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLCDNumber *lcdResultado;
    QHBoxLayout *horizontalLayout;
	QStringList listaCuentas;
	QLabel *lbtransferencia;
	DTransferencia *dtrans;
	QPushButton *btnLanzar, *btnActualizar;
	*/
	bool guardarArchivo(QString);
	void abrirArchivo(QString);
	void hacerMenus();
	bool quieresContinuar();
	void closeEvent(QCloseEvent *event);
	void addArchivoMenu(QString);
	void crearBarraStado();

public slots:

	void slotSalir();
	void slotCargarFichero(QString);
	void slotCargarFichero();
	void slotExamen();
	void slotBuscar();
	void slotInfo();
	void slotAbrir();
	void slotAbrirReciente();
	bool slotGuardar();
	bool slotGuardarComo();
	void slotNuevoFichero();
	void slotModificado();
	void slotBuscarPalabra(QString);

	/*
		void slotbotonC();
		void slotAbrirDialogo();
		void slotActualizarDialogo();
		void slotListoTransDato(float,QString);
		void slotListoTrans();
		void slotRecTrans();
	*/
};

#endif
