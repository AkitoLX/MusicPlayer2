#include "stdafx.h"
#include "GetTagOnlineDlg.h"
#include "Resource.h"
#include "Player.h"

CGetTagOnlineDlg::CGetTagOnlineDlg(const SongInfo& song, CWnd * pParent)
    : CCoverDownloadDlg(pParent), m_song_info(song)
{
}

CGetTagOnlineDlg::~CGetTagOnlineDlg()
{
}

void CGetTagOnlineDlg::OnBnClickedDownloadSelected()
{
    //MessageBox(_T("Downloan button clicked!"));
    if (m_item_selected < 0 || m_item_selected >= static_cast<int>(m_down_list.size()))
        return;
    m_item_info = m_down_list[m_item_selected];
    CPlayer::GetInstance().SetRelatedSongID(m_item_info.id);		//��ѡ����Ŀ�ĸ���ID����������

    if (m_pParentWnd != nullptr)
    {
        m_pParentWnd->SendMessage(WM_PORPERTY_ONLINE_INFO_ACQUIRED, (WPARAM)&m_item_info);
        OnCancel();
    }
}

SongInfo CGetTagOnlineDlg::GetSongInfo() const
{
    return m_song_info;
}


BOOL CGetTagOnlineDlg::OnInitDialog()
{
    CCoverDownloadDlg::OnInitDialog();

    // TODO:  �ڴ����Ӷ���ĳ�ʼ��
    SetWindowText(CCommon::LoadText(IDS_GET_TAG_ONLINE_TITLE));

    CWnd* pGetInfoBtn = GetDlgItem(IDC_DOWNLOAD_SELECTED);
    if (pGetInfoBtn != nullptr)
        pGetInfoBtn->SetWindowText(CCommon::LoadText(IDS_GET_THIS));

    return TRUE;  // return TRUE unless you set the focus to a control
                  // �쳣: OCX ����ҳӦ���� FALSE
}