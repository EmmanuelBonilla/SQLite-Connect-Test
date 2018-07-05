//---------------------------------------------------------------------------

#include <fmx.h>
#include <FireDAC.DApt.hpp>
#pragma hdrstop

#include "Test1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TconnectButton *connectButton;
//---------------------------------------------------------------------------
__fastcall TconnectButton::TconnectButton(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TconnectButton::connectButtonClick(TObject *Sender)
{
	outputMemo -> Text = " ";
	FDConnection1 -> DriverName = "SQLITE";
	FDConnection1 -> Params -> Values ["DataBase"] =
	"C:\\Users\\Public\\Documents\\Embarcadero\\Studio\\19.0\\Samples\\Data\\Employees.s3db";

	try
	{
		FDConnection1 -> Open();
		executeButton -> Enabled = true;
		outputMemo -> Lines ->Add("Connection established!");
	}
	catch (Exception& E)
	{
		outputMemo -> Text = "Exception raised with message" + E.Message;
	}
}
//---------------------------------------------------------------------------
void __fastcall TconnectButton::executeButtonClick(TObject *Sender)
{
	TFDQuery *query;
	query = new TFDQuery (NULL);

	__try
	{
		query -> Connection = FDConnection1;
		query -> SQL -> Text = "SELECT * FROM Employee";
		query -> Open();
		outputMemo -> Text = "";
		TVarRec args[3] = {"ID", "NAME", "DEPARTMENT"};
		outputMemo -> Lines -> Add (System::UnicodeString::Format("|%8s |%25s |%25s |", args, ARRAYSIZE(args) -1));

		while (!query -> Eof)
		{
			TVarRec arguments[3] = {query -> FieldByName ("ID") -> AsInteger, query->FieldByName ("Name") -> AsString, query-> FieldByName ("Department") -> AsString};
			outputMemo -> Lines -> Add (System::UnicodeString::Format("|%8d |%-25s |%-25s |", arguments, ARRAYSIZE(arguments) -1));
			query -> Next();
		}
	}
	__finally
	{
		query -> Close();
		query -> DisposeOf();
    }
}
//---------------------------------------------------------------------------/---------------------------------------------------------------------------

