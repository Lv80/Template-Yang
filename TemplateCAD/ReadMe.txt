================================================================================
    MFC 程式庫 : TemplateCAD 專案概觀
===============================================================================

應用程式精靈已經為您建立了這個 TemplateCAD 應用程式。這個應用程式
不僅示範了使用 MFC 的基本概念，也是您撰寫應用程式的起點。

這個檔案的內容摘要，包含各個構成 TemplateCAD 應用程式的檔案。

TemplateCAD.vcxproj
    這是使用應用程式精靈所產生之 VC++ 專案的主要專案檔。 
    它包含產生檔案時的 Visual C++ 版本資訊，以及使用應用程式精靈產生檔案的
    過程中，選取的平台、組態和專案功能的相關資訊。

TemplateCAD.vcxproj.filters
    這是使用應用程式精靈所產生之 VC++ 專案的篩選檔。
    檔案中含有您專案中檔案與篩選器之間關聯的相關資訊。這項關聯是用於 IDE 
    中以顯示特定節點下具有類似副檔名之檔案的群組
    (例如，".cpp" 檔案是與 "Source Files" 篩選器關聯)。

TemplateCAD.h
    這是應用程式的主要標頭檔。它包含其他專案特定的標頭 (包括 Resource.h)，
    並宣告 CTemplateCADApp 應用程式類別。

TemplateCAD.cpp
    這是主要的應用程式原始程式檔，它包含應用程式類別 CTemplateCADApp。

TemplateCAD.rc
    這份清單包含了所有程式要使用的 Microsoft Windows 資源。其中包括了儲存
    在 RES 子目錄下的圖示、點陣圖和游標。您可以直接在 Microsoft Visual C++ 
    內編輯這個檔案。您的專案資源在 1028。

res\TemplateCAD.ico
    這個圖示檔是用來做為應用程式的圖示。這個圖示包含在主要資源檔
    TemplateCAD.rc 內。

res\TemplateCAD.rc2
    這個檔案包含 Microsoft Visual C++ 編輯無法編輯的資源。您應該將所有資源
    編輯器無法編輯的資源放到這個檔案。


/////////////////////////////////////////////////////////////////////////////

應用程式精靈建立一個對話方塊類別:

TemplateCADDlg.h、TemplateCADDlg.cpp - 對話方塊
    這些檔案包含您的 CTemplateCADDlg 類別。這個類別定義應用程式主
    對話方塊的行為。對話方塊的範本在 TemplateCAD.rc 內，您可以 
    在 Microsoft Visual C++ 編輯它。


/////////////////////////////////////////////////////////////////////////////

其他功能:

ActiveX 控制項
    應用程式支援 ActiveX 控制項的使用。

/////////////////////////////////////////////////////////////////////////////

其他標準檔案:

StdAfx.h、StdAfx.cpp
    這些檔案是用來建置名為 TemplateCAD.pch 的先行編譯標頭 (PCH) 檔，
    以及名為 StdAfx.obj 的先行編譯型別檔。

Resource.h
    這是標準標頭檔，它定義新的資源 ID。
    Microsoft Visual C++ 會讀取和更新這個檔案。

TemplateCAD.manifest
	應用程式資訊清單檔案是 Windows XP 用來在並存組件的特定版本上，描述
	應用程式的相依性。載入器會利用這項資訊，從組件快取載入適當的組件，
	或者從應用程式載入私密金鑰。應用程式資訊清單可能用來做為外部  
	.manifest 檔的轉散發，這個 .manifest 檔的安裝位置，和應用程式可執行檔
	的資料夾相同，或者，它也可能以資源的形式包含在可執行檔內。 
/////////////////////////////////////////////////////////////////////////////

其他注意事項:

應用程式精靈使用 "TODO:" 來指示您應該加入或自訂的原始程式碼部分。

如果您的應用程式使用 MFC 的共用 DLL，您將需要轉散發 MFC DLL。
如果您的應用程式與作業系統的地區設定不同，您也必需轉散發對應的
當地語系化資源 MFC100XXX.DLL。如果需要這些主題的詳細資訊，請查
閱 MSDN 文件有關轉散發 Visual C++ 應用程式的章節。

/////////////////////////////////////////////////////////////////////////////
