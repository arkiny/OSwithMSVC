#pragma once
#include "windef.h"

// Ű ť�� ���� ��ũ��
// Ű ť�� �ִ� ũ��
#define KEY_MAXQUEUECOUNT	100

#pragma pack( push, 1 )

////////////////////////////////////////////////////////////////////////////////
// ���콺 ť�� ���� ��ũ��
#define MOUSE_MAXQUEUECOUNT 100

// ��ư�� ���¸� ��Ÿ���� ��ũ��
#define MOUSE_LBUTTONDOWN   0x01
#define MOUSE_RBUTTONDOWN   0x02
#define MOUSE_MBUTTONDOWN   0x04

// ��ĵ �ڵ� ���̺��� �����ϴ� �׸�
typedef struct kKeyMappingEntryStruct
{
	// Shift Ű�� Caps Lock Ű�� ���յ��� �ʴ� ASCII �ڵ�
	BYTE bNormalCode;

	// Shift Ű�� Caps Lock Ű�� ���յ� ASCII �ڵ�
	BYTE bCombinedCode;
} KEYMAPPINGENTRY;

// Ű������ ���¸� �����ϴ� �ڷᱸ��
typedef struct tag_KEYBOARDSTATE
{
	// �ڷᱸ�� ����ȭ�� ���� ���ɶ�
	//SPINLOCK stSpinLock;

	// ���� Ű ����
	bool bShiftDown;
	bool bCapsLockOn;
	bool bNumLockOn;
	bool bScrollLockOn;

	// Ȯ�� Ű�� ó���ϱ� ���� ����
	bool bExtendedCodeIn;
	int iSkipCountForPause;
} KEYBOARDSTATE;

// Ű ť�� ������ ������ ����ü
typedef struct kKeyDataStruct
{
	// Ű���忡�� ���޵� ��ĵ �ڵ�
	BYTE bScanCode;
	// ��ĵ �ڵ带 ��ȯ�� ASCII �ڵ�
	BYTE bASCIICode;
	// Ű ���¸� �����ϴ� �÷���(����/������/Ȯ�� Ű ����)
	BYTE bFlags;
} KEYDATA;

// PS/2 ���콺 ��Ŷ�� �����ϴ� �ڷᱸ��, ���콺 ť�� �����ϴ� ������
typedef struct kMousePacketStruct
{
	// ��ư ���¿� X, Y ���� ���õ� �÷���
	BYTE bButtonStatusAndFlag;
	// X�� �̵��Ÿ�
	int bXMovement;
	// Y�� �̵��Ÿ�
	int bYMovement;
	// �����ǥ������ ������ǥ�������� ��Ÿ���� �÷���
	BYTE bAbsoluteCoordinate;
} MOUSEDATA;

// ���콺�� ���¸� �����ϴ� �ڷᱸ��
typedef struct tag_MouseManagerStruct
{
	// �ڷᱸ�� ����ȭ�� ���� ���ɶ�
	//    SPINLOCK stSpinLock;    
	// ���� ���ŵ� �������� ����, ���콺 �����Ͱ� 3���̹Ƿ� 0~2�� ������ ��� �ݺ���
	int iByteCount;
	// ���� ���� ���� ���콺 ������
	MOUSEDATA stCurrentData;
} MOUSESTATE;

typedef struct tag_LinearBufferInfo
{
	unsigned long* pBuffer;
	unsigned long width;
	unsigned long height;
	unsigned long depth;
	unsigned type;
	bool isDirectVideoBuffer;

} LinearBufferInfo;

#pragma pack( pop )

class I_GUIEngine
{
public:
	virtual bool Initialize() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void SetLinearBuffer(LinearBufferInfo& linearBufferInfo) = 0;
	virtual bool PutKeyboardQueue(KEYDATA* pData) = 0;
	virtual bool PutMouseQueue(MOUSEDATA* pData) = 0;

	LinearBufferInfo m_linearBufferInfo;

};