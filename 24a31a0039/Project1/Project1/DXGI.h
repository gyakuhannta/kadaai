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
     * @brief	dxgi ファクトリーを取得する
     * @return	dxgi ファクトリーのポインタ
     */
    [[nodiscard]] IDXGIFactory4* factory() const noexcept;

    //---------------------------------------------------------------------------------
    /**
     * @brief	ディスプレイアダプターを取得する
     * @return	ディスプレイアダプターのポインタ
     */
    [[nodiscard]] IDXGIAdapter1* displayAdapter() const noexcept;

private:
    IDXGIFactory4* dxgiFactory_{};  /// DXGIを作成するファクトリー
    IDXGIAdapter1* dxgiAdapter_{};  //

	IDXGIFactory4* CreateDXGIFactory();
	IDXGIAdapter* GetHardwareAdapter(IDXGIFactory4* factory);
		ID3D12Device* CreateD3D12Device(IDXGIAdapter1* adapter);
		ID3D12CommandQueue* CreateCommandQueue(ID3D12Device* device);
		IDXGISwapChain3* CreateSwapChain(IDXGIFactory4* factory, ID3D12CommandQueue* commandQueue, HWND hwnd);
		void EnableDebugLayer();



};
