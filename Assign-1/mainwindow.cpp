#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{

  m_button = new QPushButton("Enter command", this); 
  // set size and location of the button
  m_button->setGeometry(QRect(QPoint(400, 100), QSize(150, 50)));

  // Create the button, make "this" the parent
  echoLineEdit = new QLineEdit("Input", this);
  echoLineEdit->setGeometry(QRect(QPoint(100,100), QSize(200,50)));

  //Text edit box for output
  text_edit = new QTextEdit("Output", this);
  text_edit->setReadOnly(true);
  text_edit->setGeometry(QRect(QPoint(100, 200), QSize(400, 300)));

  //Exit status
  exit_label = new QLabel("Exit Status: ", this);
  exit_label->setGeometry(QRect(QPoint(100, 550), QSize(200, 50)));

  //List of past commands
  history_list = new QListWidget(this);
  history_list->setGeometry(QRect(QPoint(100, 600), QSize(200, 200)));
  // new QListWidgetItem(tr("hello"), history_list);

  // Connect button signal to appropriate slot
  connect(m_button, &QPushButton::released, this, &MainWindow::handleButton);

  connect(history_list, SIGNAL(itemClicked(QListWidgetItem*)), 
            this, SLOT(itemClicked(QListWidgetItem*)));

} 

void MainWindow::itemClicked(QListWidgetItem *item){
  int row = history_list->currentRow();
  // std::cout << row << std::endl;
}

//On button click 
void MainWindow::handleButton()
{
  //Converts QString to string then runs input
  QString input = echoLineEdit->text();
  string command = input.toStdString();
  Command user_command(command);
  user_command.execute();
  
  //Outputs string result as QString
  QString result = QString::fromStdString(user_command.returnResult());
  text_edit->setPlainText(result);

  //Sets exit status
  string exit_status = std::to_string(user_command.getReturnCode());
  QString exit_result = QString::fromStdString(exit_status);
  exit_label->setText(exit_result);

  //Saves the line as part of history
  history.push_back(command + " (exit code:" + exit_status + ")");
  string newItem = history.back();
  char* history_item = &newItem[0];
  new QListWidgetItem(tr(history_item), history_list);

}
