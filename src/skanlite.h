/* ============================================================
 *
 * Copyright (C) 2007-2008 by Kare Sars <kare dot sars at iki dot fi>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 *  by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License.
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 *
 * ============================================================ */

#ifndef SKANLITE_H
#define SKANLITE_H

#include <libksane/ksane.h>

#include "ui_settings.h"
#include "ImageViewer.h"

namespace KSaneIface
{
    class KSaneWidget;
}

class Skanlite : public KDialog
{
    Q_OBJECT

    public:
        explicit Skanlite(const QString& device, QWidget *parent = 0);

    private:
        void buildShowImage();
        void readSettings();
        void doSaveImage(bool askFilename = true);

    private Q_SLOTS:
        void showSettingsDialog();
        void setDir();
        void imageReady(QByteArray &, int, int, int, int);
        void saveImage();
        void autoSaveImage();
        void showAboutDialog();


    private:
        KSaneIface::KSaneWidget *m_ksanew;
        Ui::SkanliteSettings     m_settingsUi;
        KDialog                 *m_settingsDialog;
        KDialog                 *m_showImgDialog;
        KDialog                 *m_profilesDialog;
        QImage                   m_img;
        ImageViewer              m_imageViewer;
        QStringList              m_filterList;
        QStringList              m_typeList;
        QString                  m_currentDir;
        bool                     m_firstImage;

};

#endif

