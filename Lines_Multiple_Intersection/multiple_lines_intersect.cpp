
#include <iostream>
#include <vector>
#include <fstream>
#include <QtGui>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <CGAL/Qt/GraphicsViewNavigation.h>
#include <CGAL/Cartesian.h>
#include <CGAL/Point_2.h>
#include <CGAL/intersections.h>
#include <QGraphicsTextItem>

typedef CGAL::Cartesian<double> K;
typedef K::Point_2 Point_2;
typedef K::Segment_2 Segment_2;

int main(int argc, char **argv) {

  Point_2 p1, p2;
  std::ifstream iFile ("input.txt", std::ios::in);
  QApplication app(argc, argv);
  QGraphicsScene scene;
  scene.setSceneRect(0,0, 500, 400);
  double y = 500.0;
  std::vector<Segment_2> segments;
  while (iFile >> p1)
  	if (iFile >> p2)
  	{
  		scene.addLine(QLineF(p1.x(),p1.y(),p2.x(),p2.y()));
  		segments.push_back(Segment_2(Point_2(p1.x(), p1.y()), Point_2(p2.x(), p2.y())));
  	}
  for (int i = 0; i < segments.size(); i++) {
    for (int j = i + 1; j < segments.size(); j++) {
      if (CGAL::do_intersect(segments[i], segments[j])) {
        auto intersection_result = CGAL::intersection(segments[i], segments[j]);
        if (const Point_2* p = boost::get<Point_2>(&*intersection_result)) {
          
            //std::cout << "Intersection found between segment " << i << " and segment " << j << " at point (" << *p << ")" << std::endl;
         	std::stringstream ss;
			ss << "Intersection found between segment " << i << " and segment " << j << " at point (" << *p << ")" << std::endl;
			std::string str = ss.str();
			std::cout << str;

		    QGraphicsTextItem *text = scene.addText(QString::fromStdString(str));
		    text->setPos(0, y);
		    y += text->boundingRect().height();
	       // QGraphicsTextItem *text = scene.addText(QString::fromStdString( ));
          
        }
      }
    }
  }
   

	QGraphicsView* view = new QGraphicsView(&scene);
	CGAL::Qt::GraphicsViewNavigation navigation;
	view->installEventFilter(&navigation);
	view->viewport()->installEventFilter(&navigation);
	view->setRenderHint(QPainter::Antialiasing);
	view->show();
	return app.exec();

}

