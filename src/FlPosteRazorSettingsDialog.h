/*
	PosteRazor - Make your own poster!
	Copyright (C) 2005-2011 by Alessandro Portale
	http://posterazor.sourceforge.net/

	This file is part of PosteRazor

	PosteRazor is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	
	PosteRazor is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License
	along with PosteRazor; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

#ifndef FLPOSTERAZORSETTINGSDIALOG_H
#define FLPOSTERAZORSETTINGSDIALOG_H

#include "UnitsOfLength.h"
#include "FlPosteRazorDialogUI.h"
#include "FlPaintCanvasGroup.h"
#include "Translations.h"

typedef struct
{
	UnitsOfLength::eUnitsOfLength unitOfLength;
	FlPaintCanvasGroup::ePaintCanvasTypes previewType;
	Translations::eLanguages language;
} posteRazorSettings;

class SettingsChangementHandler
{
public:
	virtual ~SettingsChangementHandler() {}

	virtual void handleOptionsChangement(posteRazorSettings *settings) = 0;
};

class FlPosteRazorSettingsDialog: public PosteRazorSettingsDialogUI
{
	posteRazorSettings *m_settings;
	SettingsChangementHandler *m_changementHandler;
	int m_unitOfLengthButtonsCount;
	Fl_Button **m_unitOfLengthButtons;
	int m_languageButtonsCount;
	Fl_Button **m_languageButtons;
	Fl_RGB_Image **m_languageButtonImages;

public:
	FlPosteRazorSettingsDialog();
	~FlPosteRazorSettingsDialog();

	void setOptionsAndHandler(posteRazorSettings *settings, SettingsChangementHandler *changementHandler);
	static void handleUnitOfLengthChoice_cb(Fl_Widget *widget, void *userData);
	void handleUnitOfLengthChoice(void);
	void handleUseOpenGLChangement(void);
	static void handleLanguageChoice_cb(Fl_Widget *widget, void *userData);
	void handleLanguageChoice(void);
	void updateLanguage(void);
	void show(void);
};

#endif // FLPOSTERAZORSETTINGSDIALOG_H
