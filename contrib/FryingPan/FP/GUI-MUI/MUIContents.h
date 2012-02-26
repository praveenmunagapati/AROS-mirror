/*
 * FryingPan - Amiga CD/DVD Recording Software (User Interface and supporting Libraries only)
 * Copyright (C) 2001-2011 Tomasz Wiszkowski Tomasz.Wiszkowski at gmail.com
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef _GUIMUI_MUICONTENTS_H_
#define _GUIMUI_MUICONTENTS_H_

#include <Generic/HookT.h>
#include <Generic/LibrarySpool.h>
#include "Components/MUITree.h"
#include "Components/MUIPopAsl.h"
#include "MUICommon.h"
#include <Optical/IOptItem.h>
#include "Globals.h"
#include <Generic/ConfigParser.h>

using namespace GenNS;

class MUIContents : public MUICommon
{
protected:
   struct Entry
   {
      const IOptItem   *item;
      String            number;
      String            name;
      String            info;
   };

protected:
   enum BtnID
   {
      ID_Refresh,
      ID_DownloadTracks,
   };

protected:
   Globals                   &Glb;
   unsigned long             *all;
   MUITree                   *tracks;
   ConfigParser              *Config;
   MUIPopAsl                 *target;

protected:
   HookT<MUIContents, const char**, Entry*>     hHkDisplay;
   HookT<MUIContents, void*, const IOptItem*>   hHkConstruct;
   HookT<MUIContents, void*, Entry*>            hHkDestruct;
   HookT<MUIContents, BtnID, void*>             hHkButton;

protected:

   DbgHandler                *getDebug();

protected:
   virtual unsigned long      display(const char**, Entry*);
   virtual unsigned long      construct(void*, const IOptItem*);
   virtual unsigned long      destruct(void*, Entry*);
   virtual unsigned long      button(BtnID, void*);
   virtual void               addRecurse(unsigned long parent, const IOptItem* data);

public:
                              MUIContents(ConfigParser *parent, Globals &glb);
   virtual                   ~MUIContents();
   virtual unsigned long     *getObject();
   virtual bool               start();
   virtual void               stop();
   virtual void               update();
};


#endif

