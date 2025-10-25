#pragma once
#include <d3d12.h>
#include <dxgi1_4.h>
class DXGI
{
public:
	DXGI() = default;
	~DXGI() {}
    [[nodiscard]] bool setDisplayAdapter() noexcept;

    //---------------------------------------------------------------------------------
    /**
     * @brief	dxgi �t�@�N�g���[���擾����
     * @return	dxgi �t�@�N�g���[�̃|�C���^
     */
    [[nodiscard]] IDXGIFactory4* factory() const noexcept;

    //---------------------------------------------------------------------------------
    /**
     * @brief	�f�B�X�v���C�A�_�v�^�[���擾����
     * @return	�f�B�X�v���C�A�_�v�^�[�̃|�C���^
     */
    [[nodiscard]] IDXGIAdapter1* displayAdapter() const noexcept;

private:
    IDXGIFactory4* dxgiFactory_{};  /// DXGI���쐬����t�@�N�g���[
    IDXGIAdapter1* dxgiAdapter_{};  //

	IDXGIFactory4* CreateDXGIFactory();
	IDXGIAdapter* GetHardwareAdapter(IDXGIFactory4* factory);
		ID3D12Device* CreateD3D12Device(IDXGIAdapter1* adapter);
		ID3D12CommandQueue* CreateCommandQueue(ID3D12Device* device);
		IDXGISwapChain3* CreateSwapChain(IDXGIFactory4* factory, ID3D12CommandQueue* commandQueue, HWND hwnd);
		void EnableDebugLayer();



};
