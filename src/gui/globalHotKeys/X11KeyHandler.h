/*
 * Copyright (C) 2019 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef KSNIP_X11KEYHANDLER_H
#define KSNIP_X11KEYHANDLER_H

#include <QX11Info>
#include <QVector>

#include "AbstractKeyHandler.h"
#include "KeySequenceToX11KeyCodeTranslator.h"

class X11KeyHandler : public AbstractKeyHandler
{
public:
	X11KeyHandler() = default;
	~X11KeyHandler() override;

	bool registerKey(const QKeySequence &keySequence) override;
	bool isKeyPressed(void* message) override;

private:
	KeyCodeCombo mKeyCodeCombo;
	KeySequenceToX11KeyCodeTranslator mKeyCodeMapper;
	void unregisterKey() const;
};

#endif //KSNIP_X11KEYHANDLER_H