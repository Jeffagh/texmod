/*
This file is part of OpenTexMod.


OpenTexMod is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OpenTexMod is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with FooOpenTexMod.  If not, see <http://www.gnu.org/licenses/>.
*/



#ifndef OTM_GAME_H_
#define OTM_GAME_H_
#include "OTM_Main.h"

//this class is intended as a storing object for each game
// one should ad an assignment operator,  loading and saving default values, ...
class OTM_GameInfo
{
public:
  OTM_GameInfo(const wxString &name);
  ~OTM_GameInfo(void);
  void Init(void);

  wxString Name;

  int SaveToFile() {return SaveToFile( Name);}
  int SaveToFile( const wxString &file_name);
  int LoadFromFile() {return LoadFromFile( Name);}
  int LoadFromFile( const wxString &file_name);

  int GetChecked( bool* array, int num) const;
  int SetChecked( bool* array, int num);

  int SetSaveSingleTexture(bool val);
  bool GetSaveSingleTexture(void) const {return SaveSingleTexture;}

  int SetSaveAllTextures(bool val);
  bool GetSaveAllTextures(void) const {return SaveAllTextures;}

  void SetTextures(const wxArrayString &textures);
  void GetTextures( wxArrayString &textures) const;
  void AddTexture( const wxString &textures);

  int GetNumberOfTextures(void) const {return Textures.GetCount();}

  int SendTextures(void);

  int GetKeyBack() const {return KeyBack;}
  int SetKeyBack(int key) {KeyBack=key; return 0;}

  int GetKeySave() const {return KeySave;}
  int SetKeySave(int key) {KeySave=key; return 0;}

  int GetKeyNext() const {return KeyNext;}
  int SetKeyNext(int key) {KeyNext=key; return 0;}

  int SetOpenPath(const wxString &path) {OpenPath=path; return 0;}
  wxString GetOpenPath(void) const {return OpenPath;}

  int SetSavePath(const wxString &path) {SavePath=path; return 0;}
  wxString GetSavePath(void) const {return SavePath;}

  OTM_GameInfo& operator = (const  OTM_GameInfo &rhs);

private:

  bool *Checked;
  int NumberOfChecked;
  int LengthOfChecked;

  bool SaveSingleTexture;
  bool SaveAllTextures;
  wxArrayString Textures;

  int KeyBack;
  int KeySave;
  int KeyNext;

  wxString OpenPath;
  wxString SavePath;
};


#endif /* OTM_SERVER_H_ */
