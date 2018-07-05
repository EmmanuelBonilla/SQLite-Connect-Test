//---------------------------------------------------------------------------

#ifndef Test1H
#define Test1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TconnectButton : public TForm
{
__published:	// IDE-managed Components
	TButton *executeButton;
	TButton *connectButton;
	TButton *sortButton;
	TFDConnection *FDConnection1;
	TMemo *outputMemo;
	TFDPhysSQLiteDriverLink *FDPhysSQLiteDriverLink1;

	void __fastcall connectButtonClick(TObject *Sender);
	void __fastcall executeButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TconnectButton(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TconnectButton *connectButton;
//---------------------------------------------------------------------------
#endif
