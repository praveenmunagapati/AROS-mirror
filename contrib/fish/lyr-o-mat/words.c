/*
 *  Source machine generated by GadToolsBox V1.4
 *  which is (c) Copyright 1991,92 Jaba Development
 */

#include "words.h"

struct Screen         *Scr = NULL;
UBYTE                 *PubScreenName = NULL;
APTR                   VisualInfo = NULL;
struct Window         *Project0Wnd = NULL;
struct Gadget         *Project0GList = NULL;
struct Menu           *Project0Menus = NULL;
struct IntuiMessage    Project0Msg;
struct Gadget         *Project0Gadgets[15];
UWORD                  Project0Left = 0;
UWORD                  Project0Top = 0;
UWORD                  Project0Width = 495;
UWORD                  Project0Height = 186;
UBYTE                 *Project0Wdt = (UBYTE *)LYR_NAME;
struct TextAttr       *Font, Attr;
UWORD                  FontX, FontY;
UWORD                  OffX, OffY;

UBYTE *mode0Labels[] = {
	(UBYTE *)"Pattern",
	(UBYTE *)"Text",
	NULL };

struct NewMenu Project0NewMenu[] = {
    { NM_TITLE, (STRPTR)"Project", NULL, 0, 0L, NULL, },
    { NM_ITEM, (STRPTR)"Load ", NULL, 0, 0L, NULL, },
    { NM_SUB, (STRPTR)"Pattern & Classes", (STRPTR)"L", 0, 0L, (APTR)Project0Loadall, },
    { NM_SUB, (STRPTR)"Pattern only", NULL, 0, 0L, (APTR)Project0Loadpattern, },
    { NM_SUB, (STRPTR)"Classes only", NULL, 0, 0L, (APTR)Project0Loadclasses, },
    { NM_ITEM, (STRPTR)"Append", NULL, 0, 0L, NULL, },
    { NM_SUB, (STRPTR)"Pattern & Classes", (STRPTR)"A", 0, 0L, (APTR)Project0appendall, },
    { NM_SUB, (STRPTR)"Pattern only", NULL, 0, 0L, (APTR)Project0appendpattern, },
    { NM_SUB, (STRPTR)"Classes only", NULL, 0, 0L, (APTR)Project0appendclasses, },
    { NM_ITEM, (STRPTR)"Save ", NULL, 0, 0L, NULL, },
    { NM_SUB, (STRPTR)"Pattern & Classes", (STRPTR)"S", 0, 0L, (APTR)Project0saveall, },
    { NM_SUB, (STRPTR)"Pattern only", NULL, 0, 0L, (APTR)Project0savepattern, },
    { NM_SUB, (STRPTR)"Classes only", NULL, 0, 0L, (APTR)Project0saveclasses, },
    { NM_ITEM, (STRPTR)"Save as Default", (STRPTR)"D", 0, 0L, (APTR)Project0savedefault, },
    { NM_ITEM, (STRPTR)NM_BARLABEL, NULL, 0, 0L, NULL, },
    { NM_ITEM, (STRPTR)"About...",NULL, 0, 0L, (APTR)Project0about, },
    { NM_ITEM, (STRPTR)NM_BARLABEL, NULL, 0, 0L, NULL, },
    { NM_ITEM, (STRPTR)"Quit...", (STRPTR)"Q", 0, 0L, (APTR)Project0quit, },
    { NM_TITLE, (STRPTR)"Output", NULL, 0, 0, 0, },
    { NM_ITEM, (STRPTR)"Window", (STRPTR)"W", CHECKED | CHECKIT | MENUTOGGLE, 0L, (APTR)Project0ConWd, },
    { NM_ITEM, (STRPTR)"Printer", (STRPTR)"P", CHECKIT | MENUTOGGLE, 0L, (APTR)Project0Item0, },
    { NM_TITLE, (STRPTR)"Info",NULL, 0, 0, NULL, },
    { NM_ITEM, (STRPTR)"Show complete info", (STRPTR)"I", 0, 0L, (APTR)Project0ShowInfo, },
    { NM_ITEM, (STRPTR)"Show pattern info",NULL, 0, 0L, (APTR)Project0ShowPInfo, },
    { NM_ITEM, (STRPTR)"Show class info", NULL, 0, 0L, (APTR)Project0ShowCInfo, },
    { NM_TITLE, (STRPTR)"Options",NULL, 0, 0, 0L, },
    { NM_ITEM, (STRPTR)"Write Icons", (STRPTR)"C", CHECKIT | MENUTOGGLE | CHECKED, 0L, (APTR)Project0WriteIcon, },
    { NM_END, NULL, NULL, 0, 0L, NULL },
};

UWORD Project0GTypes[] = {
	STRING_KIND,
	LISTVIEW_KIND,
	STRING_KIND,
	LISTVIEW_KIND,
	STRING_KIND,
	LISTVIEW_KIND,
	INTEGER_KIND,
	BUTTON_KIND,
	BUTTON_KIND,
	BUTTON_KIND,
	BUTTON_KIND,
	BUTTON_KIND,
	BUTTON_KIND,
	BUTTON_KIND,
  CYCLE_KIND
};

struct NewGadget Project0NGad[] = {
	{ 276, 100, 196, 14, NULL, NULL, GD_wordstring, 0, NULL, (APTR)wordstringClicked, },
	{ 276, 100, 196, 66, (UBYTE *)"Word", NULL, GD_wordlist, PLACETEXT_ABOVE, NULL, (APTR)wordlistClicked, },
	{ 11,  100, 202, 14, NULL, NULL, GD_class_string, 0, NULL, (APTR)class_stringClicked, },
	{ 11,  100, 202, 66, (UBYTE *)"Class", NULL, GD_classlist, PLACETEXT_ABOVE, NULL, (APTR)classlistClicked, },
	{ 11, 181, 461, 14, NULL, NULL, GD_templatestring, 0, NULL, (APTR)templatestringClicked, },
	{ 11, 23, 461, 64, NULL, NULL, GD_templatelist, PLACETEXT_ABOVE, NULL, (APTR)templatelistClicked, },
	{ 272, 2, 52, 13, (UBYTE *)"Number of Patterns", NULL, GD_numpat, PLACETEXT_RIGHT, NULL, (APTR)numpatClicked, },
	{ 11, 2, 118, 16, (UBYTE *)"_Generate", NULL, GD_generate, PLACETEXT_IN, NULL, (APTR)generateClicked, },
	{ 11, 83, 75, 12, (UBYTE *)"Add", NULL, GD_addtemplate, PLACETEXT_IN, NULL, (APTR)addtemplateClicked, },
	{ 397, 83, 75, 12, (UBYTE *)"Delete", NULL, GD_deltemplate, PLACETEXT_IN, NULL, (APTR)deltemplateClicked, },
	{ 11, 168, 75, 12, (UBYTE *)"Add", NULL, GD_addclass, PLACETEXT_IN, NULL, (APTR)addclassClicked, },
	{ 97, 168, 75, 12, (UBYTE *)"Delete", NULL, GD_delclass, PLACETEXT_IN, NULL, (APTR)delclassClicked, },
	{ 276, 168, 75, 12, (UBYTE *)"Add", NULL, GD_addword, PLACETEXT_IN, NULL, (APTR)addwordClicked, },
	{ 362, 168, 75, 12, (UBYTE *)"Delete", NULL, GD_delword, PLACETEXT_IN, NULL, (APTR)delwordClicked, },
	{ 133, 2, 118, 16, NULL, NULL, GD_mode, 0, 0, (APTR)modeClicked }
};

IPTR Project0GTags[] = {
	(GA_Disabled),TRUE,(GTST_MaxChars), 256, (TAG_DONE),
	(GTLV_ShowSelected), 1L, (TAG_DONE),
	(GA_Disabled),TRUE,(GTST_MaxChars), 256, (TAG_DONE),
	(GTLV_ShowSelected), 1L, (TAG_DONE),
	(GA_Disabled),TRUE,(GTST_MaxChars), 256, (TAG_DONE),
	(GTLV_ShowSelected), 1L, (TAG_DONE),
	(GTIN_Number), 1, (GTIN_MaxChars), 4, (TAG_DONE),
	(GT_Underscore),'_',(TAG_DONE),
	(GT_Underscore),'_',(TAG_DONE),
	(GT_Underscore),'_',(GA_Disabled),TRUE,(TAG_DONE),
	(GT_Underscore),'_',(TAG_DONE),
	(GT_Underscore),'_',(GA_Disabled),TRUE,(TAG_DONE),
	(GT_Underscore),'_',(GA_Disabled),TRUE,(TAG_DONE),
	(GT_Underscore),'_',(GA_Disabled),TRUE,(TAG_DONE),
	(GTCY_Labels), (IPTR)&mode0Labels[ 0 ], (GT_Underscore), '_', (TAG_DONE)
};

static UWORD ComputeX( UWORD value )
{
	return(( UWORD )((( FontX * value ) + 4 ) / 8 ));
}

static UWORD ComputeY( UWORD value )
{
	return(( UWORD )((( FontY * value ) + 4 ) / 8 ));
}

static void ComputeFont( UWORD width, UWORD height )
{
	Font = &Attr;
	Font->ta_Name = (STRPTR)GfxBase->DefaultFont->tf_Message.mn_Node.ln_Name;
	Font->ta_YSize = FontY = GfxBase->DefaultFont->tf_YSize;
	FontX = GfxBase->DefaultFont->tf_XSize;

	OffX = Scr->WBorLeft;
	OffY = Scr->RastPort.TxHeight + Scr->WBorTop + 1;

	if ( width && height ) {
		if (( ComputeX( width ) + OffX + Scr->WBorRight ) > Scr->Width )
			goto UseTopaz;
		if (( ComputeY( height ) + OffY + Scr->WBorBottom ) > Scr->Height )
			goto UseTopaz;
	}
	return;

UseTopaz:
	Font->ta_Name = (STRPTR)"topaz.font";
	FontX = FontY = Font->ta_YSize = 8;
}

int SetupScreen( void )
{
	if ( ! ( Scr = LockPubScreen( PubScreenName )))
		return( 1L );

	ComputeFont( 0, 0 );

	if ( ! ( VisualInfo = GetVisualInfo( Scr, TAG_DONE )))
		return( 2L );

	return( 0L );
}

void CloseDownScreen( void )
{
	if ( VisualInfo ) {
		FreeVisualInfo( VisualInfo );
		VisualInfo = NULL;
	}

	if ( Scr        ) {
		UnlockPubScreen( NULL, Scr );
		Scr = NULL;
	}
}

int HandleProject0IDCMP( void )
{
	struct IntuiMessage	*m;
	struct MenuItem		*n;
	int			(*func)(void);
	int			running = TRUE;

	while(( m = GT_GetIMsg( Project0Wnd->UserPort ))) {

		CopyMem(( char * )m, ( char * )&Project0Msg, (long)sizeof( struct IntuiMessage ));

		GT_ReplyIMsg( m );

		switch ( Project0Msg.Class ) {

			case	IDCMP_REFRESHWINDOW:
				GT_BeginRefresh( Project0Wnd );
				GT_EndRefresh( Project0Wnd, TRUE );
				break;

			case	IDCMP_VANILLAKEY:
				running = Project0VanillaKey();
                break;

			case	IDCMP_CLOSEWINDOW:
				running = Project0CloseWindow();
				break;

			case	IDCMP_GADGETUP:
			case	IDCMP_GADGETDOWN:
				func = ( void * )(( struct Gadget * )Project0Msg.IAddress )->UserData;
				running = func();
				break;

			case	IDCMP_MENUPICK:
				while( Project0Msg.Code != MENUNULL ) {
					n = ItemAddress( Project0Menus, Project0Msg.Code );
					func = (void *)(GTMENUITEM_USERDATA( n ));
					running = func();
					Project0Msg.Code = n->NextSelect;
				}
				break;
		}
	}
	return( running );
}

int OpenProject0Window( void )
{
	struct NewGadget	ng;
	struct Gadget	*g;
	struct TagItem	*tmp;
	UWORD		lc, tc;
	UWORD		wleft = Project0Left, wtop = Project0Top, ww, wh;

	ComputeFont( Project0Width, Project0Height );

	ww = ComputeX( Project0Width );
	wh = ComputeY( Project0Height );

	if (( wleft + ww + OffX + Scr->WBorRight ) > Scr->Width ) wleft = Scr->Width - ww;
	if (( wtop + wh + OffY + Scr->WBorBottom ) > Scr->Height ) wtop = Scr->Height - wh;

	if ( ! ( g = CreateContext( &Project0GList )))
		return( 1L );

	for( lc = 0, tc = 0; lc < Project0_CNT; lc++ ) {

		CopyMem((char * )&Project0NGad[ lc ], (char * )&ng, (long)sizeof( struct NewGadget ));

		ng.ng_VisualInfo = VisualInfo;
		ng.ng_TextAttr   = Font;
		ng.ng_LeftEdge   = OffX + ComputeX( ng.ng_LeftEdge );
		ng.ng_TopEdge    = OffY + ComputeY( ng.ng_TopEdge );
		ng.ng_Width      = ComputeX( ng.ng_Width );
		ng.ng_Height     = ComputeY( ng.ng_Height);

		if ( Project0GTypes[ lc ] == LISTVIEW_KIND ) {
			if (( tmp = FindTagItem( GTLV_ShowSelected, ( struct TagItem * )&Project0GTags[ tc ] ))) {
				if ( tmp->ti_Data ) tmp->ti_Data = (IPTR)g;
			}
		}

		Project0Gadgets[ lc ] = g = CreateGadgetA((ULONG)Project0GTypes[ lc ], g, &ng, ( struct TagItem * )&Project0GTags[ tc ] );

		while( Project0GTags[ tc ] ) tc += 2;
		tc++;

		if ( NOT g )
			return( 2L );
	}

	if ( ! ( Project0Menus = CreateMenus( Project0NewMenu, GTMN_FrontPen, 0L, TAG_DONE )))
		return( 3L );

	LayoutMenus( Project0Menus, VisualInfo, TAG_DONE );

	if ( ! ( Project0Wnd = OpenWindowTags( NULL,
				WA_Left,	wleft,
				WA_Top,		wtop,
				WA_Width,	ww + OffX + Scr->WBorRight,
				WA_Height,	wh + OffY + Scr->WBorBottom,
				WA_IDCMP,	IDCMP_VANILLAKEY | STRINGIDCMP|LISTVIEWIDCMP|INTEGERIDCMP|BUTTONIDCMP|IDCMP_MENUPICK|IDCMP_CLOSEWINDOW|IDCMP_REFRESHWINDOW,
				WA_Flags,	WFLG_DRAGBAR|WFLG_DEPTHGADGET|WFLG_CLOSEGADGET|WFLG_SMART_REFRESH|WFLG_ACTIVATE,
				WA_Gadgets,	Project0GList,
				WA_Title,	Project0Wdt,
				WA_ScreenTitle,	"Lyr-O-Mat V1.0 �1993 CEKASOFT",
				WA_PubScreen,	Scr,
				WA_MinWidth,	67,
				WA_MinHeight,	21,
				WA_MaxWidth,	640,
				WA_MaxHeight,	400,
				WA_AutoAdjust,	TRUE,
				TAG_DONE )))
	return( 4L );

	SetMenuStrip( Project0Wnd, Project0Menus );
	GT_RefreshWindow( Project0Wnd, NULL );

	return( 0L );
}

void CloseProject0Window( void )
{
	if ( Project0Menus      ) {
		ClearMenuStrip( Project0Wnd );
		FreeMenus( Project0Menus );
		Project0Menus = NULL;	}

	if ( Project0Wnd        ) {
		CloseWindow( Project0Wnd );
		Project0Wnd = NULL;
	}

	if ( Project0GList      ) {
		FreeGadgets( Project0GList );
		Project0GList = NULL;
	}
}
