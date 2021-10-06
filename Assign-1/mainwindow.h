/*
Author: Terrence Ju
Header file for main window
Oct 5, 2021
*/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QApplication>
#include <QGuiApplication>
#include <QLabel> 
#include <QAccessibleTextInterface>
#include <QLineEdit>
#include <QTextEdit>
#include <QString>
#include <QListWidget>
#include <QListWidgetItem>
#include <vector>
#include <cstring>
#include "code.h"

namespace Ui { //Defines namespace for Main Window
  class MainWindow;
}
 
class MainWindow : public QMainWindow //Defines main window and creates object
{
  Q_OBJECT

public: //Defines methods
  explicit MainWindow(QWidget *parent = nullptr);
  void printOutput(string userInput, bool inputMethod);

private slots: //Defines event handlers
  void itemClicked(QListWidgetItem *item);
  void handleButton();

private: //Defines data members, UI objects and vectors storing history
  QPushButton *command_button;
  QLineEdit *input_box;
  QTextEdit *output_box;
  QLabel *exit_label;
  QLabel *input_label;
  QLabel *output_label;
  QLabel *history_label;
  std::vector<string> history;
  QListWidget *history_list;
  std::vector<Command> command_history;
  int historyNum;
};

#endif 