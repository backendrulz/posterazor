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

#ifndef FLPOSTERAZORHELPDIALOG_H
#define FLPOSTERAZORHELPDIALOG_H

#include "FlPosteRazorDialogUI.h"

class FlPosteRazorHelpDialog: public PosteRazorHelpDialogUI
{
public:
	FlPosteRazorHelpDialog();

	void setHtmlContent(const char *content);
	void jumpToAnchor(const char *anchor);
	void handleHomepageButtonClick(void);
	void openURLInBrowser(const char* url);
	static const char *linkCallback(Fl_Widget *w, const char *uri);
	void updateLanguage(void);
};

#endif // FLPOSTERAZORHELPDIALOG_H
