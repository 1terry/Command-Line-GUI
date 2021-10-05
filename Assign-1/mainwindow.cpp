#include "mainwindow.h"

using namespace boost::process;

//Check code and make better names

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  //Initializes window 
  this ->setMinimumSize(600,800);
  historyNum = 0;

  //Input box, label, and button
  input_label = new QLabel("Input", this);
  input_label->setGeometry(QRect(QPoint(50,0), QSize(200,50)));
  echoLineEdit = new QLineEdit(this);
  echoLineEdit->setGeometry(QRect(QPoint(50,50), QSize(300,35)));
  m_button = new QPushButton("Enter command", this); 
  m_button->setGeometry(QRect(QPoint(375, 50), QSize(150, 35)));

  //Output box and label
  output_label = new QLabel("Output", this);
  output_label -> setGeometry(QRect(QPoint(50, 100), QSize(500, 50)));
  text_edit = new QTextEdit(this);
  text_edit->setReadOnly(true);
  text_edit->setGeometry(QRect(QPoint(50, 135), QSize(500, 300)));

  //Exit status and history
  history_label = new QLabel("History", this);
  history_label->setGeometry(QRect(QPoint(50, 425), QSize(300, 50)));
  exit_label = new QLabel("Exit Status: ", this);
  exit_label->setGeometry(QRect(QPoint(300, 425), QSize(500, 50)));
  history_list = new QListWidget(this);
  history_list->setGeometry(QRect(QPoint(50, 475), QSize(500, 300)));

  // Connect button signal to appropriate slot
  connect(m_button, &QPushButton::released, this, &MainWindow::handleButton);
  connect(history_list, SIGNAL(itemClicked(QListWidgetItem*)), 
            this, SLOT(itemClicked(QListWidgetItem*)));
} 

//On history item clicked
void MainWindow::itemClicked(QListWidgetItem *item){
  int row = history_list->currentRow();
  
  //Returns and prints output from history
  QString result = QString::fromStdString(command_history[row].returnResult());
  text_edit->setText(result);

  //Returns and prints exit status from history
  string exit_status = std::to_string(command_history[row].getReturnCode());
  QString exit_result = QString::fromStdString("exit status: " + exit_status);
  exit_label->setText(exit_result);
}

//On button clicked
void MainWindow::handleButton()
{
  //Converts QString to string then runs input
  QString input = echoLineEdit->text();
  string input_command = input.toStdString();

  //Executes command and displays output
  Command user_command(input_command);
  user_command.execute();
  QString result = QString::fromStdString(user_command.returnResult());
  text_edit->setPlainText(result);

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

