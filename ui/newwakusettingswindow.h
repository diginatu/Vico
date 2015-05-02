﻿#ifndef NEWWAKUSETTINGSWINDOW_H
#define NEWWAKUSETTINGSWINDOW_H

#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>

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
  void songRightsApply();

  bool isSetNecessary();
  bool isTwitterTagValid();

  void savePresets();
  void loadPresets();

  void resetWakuData();
  void clearWakuDataIfNeeded();

  QString getCommunity();
private:
  Ui::NewWakuSettingsWindow *ui;
  MainWindow* mwin;
  QString selectedCommunity, selectedCategory;
  bool clearWakuData = false;

  QJsonObject makeJsonFromForm();
  void setPresetsFromJson(const QJsonObject& jsn);
  void clearListForm();
private slots:
  void on_befWakuReuse_clicked();
  void on_tag_add_clicked();
  void on_tag_delete_clicked();
  void on_presets_regist_clicked();
  void on_presets_delete_clicked();
  void on_presetes_activated(int index);
  void on_clear_clicked();
  void on_okButton_clicked();
  void dragEnterEvent(QDragEnterEvent* event);
  void dropEvent(QDropEvent* event);
  void on_getTag_clicked();
  void on_song_csv_open_clicked();
  void on_song_csv_clear_clicked();
};

#endif // NEWWAKUSETTINGSWINDOW_H
