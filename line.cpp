#include <iostream>
#include <fstream>
#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <CGAL/Qt/GraphicsViewNavigation.h>
int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	QGraphicsScene scene;
	scene.setSceneRect(0, 0, 300, 300);
	scene.addLine(QLineF(20, 30, 250, 200));

	QGraphicsView *view = new QGraphicsView(&scene);
	CGAL::Qt::GraphicsViewNavigation navigation;
	view->installEventFilter(&navigation);
	view->viewport()->installEventFilter(&navigation);
	view->setRenderHint(QPainter::Antialiasing);
	view->show();
	return app.exec();
}
