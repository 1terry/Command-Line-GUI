/*
Author: Terrence Ju
Code for bootstrapping and running application
Oct 5, 2021
*/

#include "mainwindow.h"
 
/*
Main method runs application and shows main window
*/
int main(int argc, char *argv[]) 
{
  QApplication app(argc, argv);
  MainWindow mainWindow;
  mainWindow.show();
  return app.exec();
}