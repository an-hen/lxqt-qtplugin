/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * LXDE-Qt - a lightweight, Qt based, desktop toolset
 * http://lxde.org/
 *
 * Copyright: 2014 LXQt team
 * Authors:
 *   Hong Jen Yee (PCMan) <pcman.tw@gmail.com>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */
 
#ifndef LXQTPLATFORMTHEME_H
#define LXQTPLATFORMTHEME_H

#include <qpa/qplatformtheme.h>
#include <QtGlobal>
#include <LXQt/Settings>

class Q_GUI_EXPORT LXQtPlatformTheme : public QObject, public QPlatformTheme {
    Q_OBJECT
public:
    LXQtPlatformTheme();
    ~LXQtPlatformTheme();

    // virtual QPlatformMenuItem* createPlatformMenuItem() const;
    // virtual QPlatformMenu* createPlatformMenu() const;
    // virtual QPlatformMenuBar* createPlatformMenuBar() const;

    virtual bool usePlatformNativeDialog(DialogType type) const;
    // virtual QPlatformDialogHelper *createPlatformDialogHelper(DialogType type) const;

    // virtual const QPalette *palette(Palette type = SystemPalette) const;

    // virtual const QFont *font(Font type = SystemFont) const;

    virtual QVariant themeHint(ThemeHint hint) const;

    // virtual QPixmap standardPixmap(StandardPixmap sp, const QSizeF &size) const;
    // virtual QPixmap fileIconPixmap(const QFileInfo &fileInfo, const QSizeF &size,
    //                               QPlatformTheme::IconOptions iconOptions = 0) const;

    // virtual QIconEngine *createIconEngine(const QString &iconName) const;

    // virtual QList<QKeySequence> keyBindings(QKeySequence::StandardKey key) const;

    // virtual QString standardButtonText(int button) const;

private:
    void loadIconTheme();
    void loadSettings();
    void notifyChange();
  
private Q_SLOTS:
    void onIconThemeChanged();
    void onSettingsChanged();

private:
    // LXQt settings
    QString iconTheme_;
    Qt::ToolButtonStyle toolButtonStyle_;
    bool singleClickActivate_;

    // other Qt settings
};

#endif // LXQTPLATFORMTHEME_H
