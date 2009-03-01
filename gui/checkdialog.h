/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2009 Daniel Marjamäki, Reijo Tomperi, Nicolas Le Cam,
 * Leandro Penz, Kimmo Varis, Vesa Pikki
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/
 */


#ifndef CHECKDIALOG_H
#define CHECKDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QComboBox>
#include <QSettings>
#include "../src/settings.h"
#include <QVBoxLayout>
#include <QTreeView>
#include <QDirModel>
#include <QStandardItem>

/**
* @brief Dialog to select what and how to check
*
*/
class CheckDialog : public QDialog
{
    Q_OBJECT
public:
    CheckDialog(QSettings &programSettings);
    virtual ~CheckDialog();

    /**
    * @brief Get cppcheck settings based on user selections
    *
    * @return cppcheck settings
    */
    Settings GetSettings();

    /**
    * @brief Get the root path of current selection
    *
    * @return default path to use next time
    */
    QString GetDefaultPath();

    /**
    * @brief Get a list of selected files and directories
    *
    * @return list of selected files
    */
    QStringList GetSelectedFiles();

    /**
    * @brief Save all checkbox values
    *
    */
    void SaveCheckboxValues();
protected:

    /**
    * @brief Load saved values
    * Loads dialog size and column widths.
    *
    */
    void SaveSettings();

    /**
    * @brief Save settings
    * Save dialog size and column widths.
    *
    */
    void LoadSettings();

    /**
    * @brief Save a single checkboxes value
    *
    * @param box checkbox to save
    * @param name name for QSettings to store the value
    */
    void SaveCheckboxValue(QCheckBox *box, const QString &name);

    /**
    * @brief Add a new checkbox to layout
    *
    * @param layout layout to add to
    * @param label label for the checkbox
    * @param settings QSettings name for default value
    * @return newly created QCheckBox
    */
    QCheckBox* AddCheckbox(QVBoxLayout *layout,
                           const QString &label,
                           const QString &settings,
                           bool value);

    /**
    * @brief Convert bool to Qt::CheckState
    *
    * @param yes value to convert
    * @return value converted to Qt::CheckState
    */
    Qt::CheckState BoolToCheckState(bool yes);

    /**
    * @brief Converts Qt::CheckState to bool
    *
    * @param state Qt::CheckState to convert
    * @return converted value
    */
    bool CheckStateToBool(Qt::CheckState state);

    /**
    * @brief Item model for mFileTree
    *
    */
    QDirModel mModel;

    /**
    * @brief Filetree to select files from
    *
    */
    QTreeView *mFileTree;

    /**
    * @brief How many threads should cppcheck have
    *
    */
    QLineEdit *mJobs;

    /**
    * @brief Cppcheck setting
    *
    */
    QCheckBox *mShowAll;

    /**
    * @brief Cppcheck setting
    *
    */
    QCheckBox *mCheckCodingStyle;

    /**
    * @brief Cppcheck setting
    *
    */
    QCheckBox *mErrorsOnly;

    /**
    * @brief Cppcheck setting
    *
    */
    QCheckBox *mVerbose;

    /**
    * @brief Cppcheck setting
    *
    */
    QCheckBox *mForce;

    /**
    * @brief Cppcheck setting
    *
    */
    QCheckBox *mXml;

    /**
    * @brief Cppcheck setting
    *
    */
    QCheckBox *mUnusedFunctions;

    /**
    * @brief Cppcheck setting
    *
    */
    QCheckBox *mSecurity;

    /**
    * @brief Cppcheck setting
    *
    */
    QCheckBox *mVcl;

    /**
    * @brief Settings
    *
    */
    QSettings &mSettings;


private:
};

#endif // CHECKDIALOG_H
