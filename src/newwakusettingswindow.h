﻿#ifndef NEWWAKUSETTINGSWINDOW_H
#define NEWWAKUSETTINGSWINDOW_H

#include <QDialog>
#include <QInputDialog>

class MainWindow;

namespace Ui {
class NewWakuSettingsWindow;
}

class NewWakuSettingsWindow : public QDialog
{
  Q_OBJECT

public:
  explicit NewWakuSettingsWindow(MainWindow* mwin, QWidget *parent = 0);
  ~NewWakuSettingsWindow();

  void formInit();
  void listStateSave();
  void setIndex(QString name, QString value);
  void set(QString name, QString value, QString disp = QString());
  void listStateLoad();

  void setSelectedCommunity(const QString& value);
  void setSelectedCategory(const QString& value);

  void applySettingsPostData();

  bool isSetNecessary();
  bool isTwitterTagValid();
private:
  Ui::NewWakuSettingsWindow *ui;
  MainWindow* mwin;
  QString selectedCommunity, selectedCategory;

  void makeJsonFromForm();
private slots:
  void on_befWakuReuse_clicked();
  void on_tag_add_clicked();
  void on_tag_delete_clicked();
  void on_presets_regist_clicked();
  void on_presets_delete_clicked();
};

#endif // NEWWAKUSETTINGSWINDOW_H