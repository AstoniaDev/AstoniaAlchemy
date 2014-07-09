/**
* Project:	Astonia Alchemy Utility
* Copyright Bloodknight Studios, 2013
*/

#include <windows.h>
#include <commctrl.h>
#include <iostream>
#include <string>
#include <shellapi.h>
#include "resource.h"
#include "alchemy.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "version.h"

#ifdef __cplusplus
}
#endif



using namespace std;



char strbuf1[255];

HINSTANCE hInst;
BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
        string caption;
        caption = "Astonia Alchemy Calculator ";
        caption += FULLVERSION_STRING;
        SetWindowText (hwndDlg, caption.c_str());
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndDlg, 0);
    }
    return TRUE;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        case IDC_Calculate:
            cout<<endl<<"=============================================================================="<<endl;
            /** Initialise*/
            Flask.PPS=0;
            Flask.Count=0;
            Flask.Power=0;
            Flask.ShroomA=Flask.ShroomB=Flask.ShroomC=Flask.ShroomD=Flask.ShroomE=0;
            Flask.ShroomF=Flask.ShroomG=Flask.ShroomH=Flask.ShroomI=0;
            Flask.FlowerA=Flask.FlowerB=Flask.FlowerC=Flask.FlowerD=Flask.FlowerE=Flask.FlowerF=Flask.FlowerG=0;
            Flask.Berry1=Flask.Berry2=Flask.Berry3=Flask.Berry4=0;

            string contents = "";


            /**  Check for moon phases and Profession*/
            if (SendDlgItemMessage(hwndDlg, IDC_Solstice, BM_GETCHECK, 0, 0) == BST_CHECKED)
            {
                Flask.solstice = 1;
            }else{
                Flask.solstice = 0;
            }
            if (SendDlgItemMessage(hwndDlg, IDC_Equinox, BM_GETCHECK, 0, 0) == BST_CHECKED)
            {
                if (!Flask.solstice) {Flask.equinox = 1;}
            }else{
                Flask.equinox = 0;
            }
            if (SendDlgItemMessage(hwndDlg, IDC_Fullmoon, BM_GETCHECK, 0, 0) == BST_CHECKED)
            {
                Flask.fullmoon = 1;
            }else{
                Flask.fullmoon = 0;
            }

            Flask.PPS = GetDlgItemInt(hwndDlg, IDC_PPS, NULL, FALSE);



            /** Flower inputs*/
            std::string flower1, flower2, flower3, flower4, flower5, flower6, flower7;
            Flask.FlowerCount=0;
            if (GetDlgItemText(hwndDlg, IDC_Flower1, strbuf1, 2)){
                flower1= strbuf1;
                ValidateFlower(flower1);
            }

            if (GetDlgItemText(hwndDlg, IDC_Flower2, strbuf1, 2)){
                flower2= strbuf1;
                ValidateFlower(flower2);
            }

            if (GetDlgItemText(hwndDlg, IDC_Flower3, strbuf1, 2)){
                flower3= strbuf1;
                ValidateFlower(flower3);
            }

            if (GetDlgItemText(hwndDlg, IDC_Flower4, strbuf1, 2)){
                flower4= strbuf1;
                ValidateFlower(flower4);
            }

            if (GetDlgItemText(hwndDlg, IDC_Flower5, strbuf1, 2)){
                flower5= strbuf1;
                ValidateFlower(flower5);
            }

            /** Mushroom Inputs*/
            std::string shroom1, shroom2;
            Flask.ShroomCount=0;
            if (GetDlgItemText(hwndDlg, IDC_Shroom1, strbuf1, 2)){
                shroom1= strbuf1;
                ValidateShroom(shroom1);
            }
            if (GetDlgItemText(hwndDlg, IDC_Shroom2, strbuf1, 2)){
                shroom2= strbuf1;
                ValidateShroom(shroom2);
            }


            /** Berry Inputs*/
            std::string berry;
            if (GetDlgItemText(hwndDlg, IDC_Berry, strbuf1, 2)){
                berry= strbuf1;
                ValidateBerry(berry);

            }

            /** Stone Inputs*/
            Flask.StoneE = GetDlgItemInt(hwndDlg, IDC_Stone1, NULL, FALSE);
            Flask.Count+=Flask.StoneE;

            Flask.StoneF = GetDlgItemInt(hwndDlg, IDC_Stone2, NULL, FALSE);
            Flask.Count+=Flask.StoneF;

            Flask.StoneI = GetDlgItemInt(hwndDlg, IDC_Stone3, NULL, FALSE);
            Flask.Count+=Flask.StoneI;

            Flask.StoneH = GetDlgItemInt(hwndDlg, IDC_Stone4, NULL, FALSE);
            Flask.Count+=Flask.StoneH;


            /** Do calculations */
            Flask.Power=GetPower();


            // DEBUGGING SECTION
            /*
            contents+="------------- DEBUG DATA -------------\r\n";
            contents+="Flowers ";
            if (Flask.FlowerA) {
                contents+="A:"+itostr(Flask.FlowerA)+"; ";
            }
            if (Flask.FlowerB) {
                contents+="B:"+itostr(Flask.FlowerB)+"; ";
            }
            if (Flask.FlowerC) {
                contents+="C:"+itostr(Flask.FlowerC)+"; ";
            }
            if (Flask.FlowerD) {
                contents+="D:"+itostr(Flask.FlowerD)+"; ";
            }
            if (Flask.FlowerE) {
                contents+="E:"+itostr(Flask.FlowerE)+"; ";
            }
            if (Flask.FlowerF) {
                contents+="F:"+itostr(Flask.FlowerF)+"; ";
            }
            if (Flask.FlowerG) {
                contents+="G:"+itostr(Flask.FlowerG)+"; ";
            }
            contents+="\r\n";

            contents+="Shrooms ";
            if (Flask.ShroomA) {
                contents+="A:"+itostr(Flask.ShroomA)+"; ";
            }
            if (Flask.ShroomB) {
                contents+="B:"+itostr(Flask.ShroomB)+"; ";
            }
            if (Flask.ShroomC) {
                contents+="C:"+itostr(Flask.ShroomC)+"; ";
            }
            if (Flask.ShroomD) {
                contents+="D:"+itostr(Flask.ShroomD)+"; ";
            }
            if (Flask.ShroomE) {
                contents+="E:"+itostr(Flask.ShroomE)+"; ";
            }
            if (Flask.ShroomF) {
                contents+="F:"+itostr(Flask.ShroomF)+"; ";
            }
            if (Flask.ShroomG) {
                contents+="G:"+itostr(Flask.ShroomG)+"; ";
            }
            if (Flask.ShroomH) {
                contents+="H:"+itostr(Flask.ShroomH)+"; ";
            }
            if (Flask.ShroomI) {
                contents+="I:"+itostr(Flask.ShroomI)+"; ";
            }
            contents+="\r\n";

            if(Flask.Berry1) {
                contents+="Berry: A \r\n";
            }
            if(Flask.Berry2) {
                contents+="Berry: B \r\n";
            }
            if(Flask.Berry3) {
                contents+="Berry: C \r\n";
            }
            if(Flask.Berry4) {
                contents+="Berry: D \r\n";
            }

            if (Flask.StoneE) {
                contents += "E = " + itostr(Flask.StoneE);
            }
            if (Flask.StoneF) {
                contents += "Stone F = " + itostr(Flask.StoneF);
            }
            if (Flask.StoneI) {
                contents += "Stone I = " + itostr(Flask.StoneI);
            }
            if (Flask.StoneH) {
                contents += "Stone H = " + itostr(Flask.StoneH);
            }
            contents+="\r\n";


            contents+="------------- DEBUG DATA -------------\r\n";
*/
            // DEBUGGING SECTION

            SetDuration();

            makePotion();

            contents+="Potion Results\r\n\r\n";


            //contents+="\r\n";

            if (Flask.ValueA > 0) {
                contents += getSkillName(Flask.ModA) + ": +"+itostr(Flask.ValueA) + "\r\n";
            }
            if (Flask.ValueB > 0) {
                contents += getSkillName(Flask.ModB) + ": +"+itostr(Flask.ValueB) + "\r\n";
            }
            if (Flask.ValueC > 0) {
                contents += getSkillName(Flask.ModC) + ": +"+itostr(Flask.ValueC) + "\r\n";
            }
            contents+=+"\r\n";
            if (Flask.Duration)
                contents+="Duration "+itostr(Flask.Duration)+" mins"+"\r\n"+"\r\n";

            if (Flask.solstice) {
                contents += "It is a solstice potion\r\n";
            }
            if (Flask.fullmoon) {
                contents += "It is fullmoon potion\r\n";
            }
            if (Flask.equinox) {
                contents += "It is equinox\r\n";
            }
            if (Flask.PPS){
                contents+="Alchemy Profession = "+itostr(Flask.PPS)+"\r\n";
            }
            if (Flask.Count > 9)
                contents+="***** ERROR More than 9 items not allowed!";



            SetDlgItemText(hwndDlg, IDC_Results, contents.c_str());

            /** Build output string*/


            //MessageBox(NULL, (LPCSTR)GetDlgItemText(hwndDlg, IDC_Flower1, strbuf, 3), (LPCSTR)"ERROR", MB_ICONWARNING | MB_OK | MB_DEFBUTTON2 );



        }
    }
    return TRUE;
    }
    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
