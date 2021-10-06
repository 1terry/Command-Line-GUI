/*
Author: Terrence Ju
Code for creating the UI and frontend and integrating it with code.cpp
Code calls on the class Command defined in code.cpp to run commands
Oct 5, 2021
*/

#include "mainwindow.h"

using namespace boost::process;

/*
  Method Mainwindow() initializes UI window
*/
MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  //Initializes window with set size, may have to adjust for smaller screens 
  this ->setMinimumSize(550,800);
  historyNum = 0;

  //Input box, label, and button are initialized with set position
  input_label = new QLabel("Input", this);
  input_label->setGeometry(QRect(QPoint(25,10), QSize(200,50)));
  input_box = new QLineEdit(this);
  input_box->setGeometry(QRect(QPoint(25,50), QSize(325,35)));
  command_button = new QPushButton("Enter command", this); 
  command_button->setGeometry(QRect(QPoint(400, 50), QSize(125, 35)));

  //Output box and label are initialized with set position
  output_label = new QLabel("Output", this);
  output_label -> setGeometry(QRect(QPoint(25, 100), QSize(500, 50)));
  output_box = new QTextEdit(this);
  output_box->setReadOnly(true);
  output_box->setGeometry(QRect(QPoint(25, 135), QSize(500, 300)));

  //Exit status and history are initialized with set position
  history_label = new QLabel("History", this);
  history_label->setGeometry(QRect(QPoint(25, 435), QSize(300, 50)));
  exit_label = new QLabel("Exit Status: ", this);
  exit_label->setGeometry(QRect(QPoint(400, 435), QSize(500, 50)));
  history_list = new QListWidget(this);
  history_list->setGeometry(QRect(QPoint(25, 475), QSize(500, 300)));

  // Connect button signal to appropriate slot
  connect(command_button, &QPushButton::released, this, &MainWindow::handleButton);
  connect(history_list, SIGNAL(itemClicked(QListWidgetItem*)), 
            this, SLOT(itemClicked(QListWidgetItem*)));
} 

/*
  Method handles events from clicking on list item, taking in QWidget list
*/
void MainWindow::itemClicked(QListWidgetItem *item){
  int row = history_list->currentRow();
  
  //Returns and prints output from history
  QString result = QString::fromStdString(command_history[row].returnResult());
  output_box->setText(result);

  //Returns and prints exit status from history
  string exit_status = std::to_string(command_history[row].getReturnCode());
  QString exit_result = QString::fromStdString("exit status: " + exit_status);
  exit_label->setText(exit_result);
}

/*
  Function handleButton() handles events on button click
*/
void MainWindow::handleButton()
{
  //Converts QString to string then runs input
  QString input = input_box->text();
  string input_command = input.toStdString();

  //Executes command and displays output
  Command user_command(input_command);
  user_command.execute();
  QString result = QString::fromStdString(user_command.returnResult());
  output_box->setPlainText(result);

  //Sets exit status
  string exit_status = std::to_string(user_command.getReturnCode());
  QString exit_result = QString::fromStdString("exit status: " + exit_status);
  exit_label->setText(exit_result);

  //Stores item in history and displays
  historyNum++;
  string history_position = std::to_string(historyNum);
  history.push_back(history_position + ". " + input_command + " (exit code: " + exit_status + ")");
  string newItem = history.back();
  char* history_item = &newItem[0];
  new QListWidgetItem(tr(history_item), history_list);
  command_history.push_back(user_command);
}

