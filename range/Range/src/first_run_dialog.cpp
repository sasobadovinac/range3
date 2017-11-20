/*********************************************************************
 *  AUTHOR: Tomas Soltys                                             *
 *  FILE:   first_run_dialog.cpp                                     *
 *  GROUP:  Range                                                    *
 *  TYPE:   source file (*.cpp)                                      *
 *  DATE:   16-th November 2017                                      *
 *                                                                   *
 *  DESCRIPTION: First run dialog class definition                   *
 *********************************************************************/

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QIcon>

#include "first_run_dialog.h"
#include "application_settings_dialog.h"
#include "main_settings.h"

FirstRunDialog::FirstRunDialog(QWidget *parent)
    : QDialog(parent)
{
    QIcon preferencesIcon(":/icons/file/pixmaps/range-preferences.svg");
    QIcon startIcon(":/icons/file/pixmaps/range-startup.svg");
    QIcon rangeIcon(":/icons/logos/pixmaps/range-logo-128.png");

    this->setWindowTitle(tr("First run"));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    this->setLayout(mainLayout);

    QHBoxLayout *logoLayout = new QHBoxLayout;
    mainLayout->addLayout(logoLayout);

    QLabel *logoLabel = new QLabel;
    logoLabel->setPixmap(rangeIcon.pixmap(QSize(128,128)));
    logoLayout->addWidget(logoLabel);

    QString labelMsg = "<h2>" + RVendor::name + "</h2>"
                     + "<h3>" + RVendor::description + "</h3>"
                     + "<p>" + tr("version") + ": " + RVendor::version.toString() + "</p>"
                     + "<p><strong>" + tr("Welcome") + "!</strong></p>";

    QLabel *label = new QLabel(labelMsg);
    logoLayout->addWidget(label);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    mainLayout->addLayout(buttonsLayout);

    QPushButton *applicationSettingsButton = new QPushButton(preferencesIcon, tr("Application settings"));
    buttonsLayout->addWidget(applicationSettingsButton);
    QObject::connect(applicationSettingsButton,&QPushButton::clicked,this,&FirstRunDialog::onApplicationSettingsButtonClicked);

    buttonsLayout->addStretch(1);

    QPushButton *closeButton = new QPushButton(startIcon, tr("Start"));
    buttonsLayout->addWidget(closeButton);
    QObject::connect(closeButton,&QPushButton::clicked,this,&FirstRunDialog::accept);
}

void FirstRunDialog::onApplicationSettingsButtonClicked(bool checked)
{
    ApplicationSettingsDialog(MainSettings::getInstance().getApplicationSettings(),this).exec();
}