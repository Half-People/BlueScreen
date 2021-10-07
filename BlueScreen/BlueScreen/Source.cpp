#include <Windows.h>
#include <iostream>

#pragma comment (lib,"ntdll.lib")

EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);

EXTERN_C NTSTATUS NTAPI NtRaiseHardError(NTSTATUS, ULONG, ULONG, PULONG_PTR, ULONG, PULONG);


int main()
{
	BOOLEAN bl;
	RtlAdjustPrivilege(19, TRUE, FALSE, &bl);
	unsigned long response;
	NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, 0, 6, &response);
	return 0;
}