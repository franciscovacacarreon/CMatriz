// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPrincipal.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

CMatriz *matrizA = new CMatriz();
CMatriz *matrizB  = new CMatriz();
CMatriz *matrizR = new CMatriz();

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

void TForm1::cargarSGMatriz(TStringGrid *SG, CMatriz *matriz) {
	for (int i = 0; i < matriz->getFila(); i++) {
		for (int j = 0; j < matriz->getColumna(); j++) {
			float elemento = StrToFloat(SG->Cells[j][i]);
			matriz->setElemento(i, j, elemento);
		}
	}
}

void TForm1::mostrarSGMatriz(TStringGrid *SG, CMatriz *matriz) {
	SG->RowCount = matriz->getFila();
	SG->ColCount = matriz->getColumna();

	for (int i = 0; i < matriz->getFila(); i++) {
		for (int j = 0; j < matriz->getColumna(); j++) {
			SG->Cells[j][i] = matriz->getElemento(i, j);
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	matrizA->setFila(StrToInt(EFila->Text));
	matrizA->setColumna(StrToInt(EColumna->Text));

	SGMatrizA->RowCount = matrizA->getFila();
	SGMatrizA->ColCount = matrizA->getColumna();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
	cargarSGMatriz(SGMatrizA, matrizA);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	mostrarSGMatriz(SGMatrizB, matrizA);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender) {
	cargarSGMatriz(SGMatrizA, matrizA);
	matrizA->eliminarFila(StrToInt(EFila2->Text));
	mostrarSGMatriz(SGMatrizB, matrizA);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender) {
	cargarSGMatriz(SGMatrizA, matrizA);
	matrizA->eliminarColumna(StrToInt(EColumna2->Text));
	mostrarSGMatriz(SGMatrizB, matrizA);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender) {
	cargarSGMatriz(SGMatrizA, matrizA);
	matrizR = matrizA->subMatriz(StrToInt(EFila2->Text),
		StrToInt(EColumna2->Text));
	mostrarSGMatriz(SGMatrizB, matrizR);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender) {
	cargarSGMatriz(SGMatrizA, matrizA);
	ShowMessage(matrizA->elementoMasRepetido());
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender) {
	cargarSGMatriz(SGMatrizA, matrizA);
	int fila = StrToInt(EFila2->Text) - 1;
	int columna = StrToInt(EColumna2->Text) - 1;
	matrizA->intercambiarFilaColumna(fila, columna);
	mostrarSGMatriz(SGMatrizB, matrizA);
}
// ---------------------------------------------------------------------------


void __fastcall TForm1::Button9Click(TObject *Sender)
{
	cargarSGMatriz(SGMatrizA, matrizA);
	ShowMessage(matrizA->sumarDiagonalSecundaria());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	matrizB->setFila(StrToInt(EFila->Text));
	matrizB->setColumna(StrToInt(EColumna->Text));

	SGMatrizB->RowCount = matrizB->getFila();
	SGMatrizB->ColCount = matrizB->getColumna();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	 cargarSGMatriz(SGMatrizA, matrizA);
	 cargarSGMatriz(SGMatrizB, matrizB);

	 bool resultado = matrizR->verificarMatrices(matrizA, matrizB);
	 if (resultado) {
		ShowMessage("Matrices iguales");
	 }  else {
	 	ShowMessage("Matrices no son iguales");
	 }
}
//---------------------------------------------------------------------------

