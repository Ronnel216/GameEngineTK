/// <summary>
/// #pragma once
/// </summay>

#include <d3d11.h>
#include <SimpleMath.h>

class Camera
{
private:
public:
	Camera(int width, int height);


	virtual ~Camera();

	// 更新
	void Update();


	// ビュー行列を返す
	const DirectX::SimpleMath::Matrix& View() const{
		return view;
	}

	// プロジェクション行列を返す
	const DirectX::SimpleMath::Matrix& Proj() const{
		return proj;
	};

	// 始点座標のセット
	void EyePos(DirectX::SimpleMath::Vector3 eyePos){
		this->eyePos = eyePos;
	};

	// 参照点のセット
	void RefPos(DirectX::SimpleMath::Vector3 refPos) {
		this->refPos = refPos;
	};

	// カメラの上方向ベクトル
	void VpVec(DirectX::SimpleMath::Vector3 vpVec) {
		this->vpVec = vpVec;
	};
	// ビュー行列
	void View(DirectX::SimpleMath::Matrix view) {
		this->view = view;
	};
	// プロジェクション行列
	void Proj(DirectX::SimpleMath::Matrix proj) {
		this->proj = proj;
	};
	// 視野角
	void FovY(float fovY) {
		this->fovY = fovY;
	};
	// アスペクト比
	void Aspect(float aspect) {
		this->aspect = aspect;
	};
	// ニアクリップ
	void NearClip(float nearClip) {
		this->nearClip = nearClip;
	};
	// ファークリップ
	void FarClip(float farClip) {
		this->farClip = farClip;
	};


protected:
	// カメラの位置
	DirectX::SimpleMath::Vector3 eyePos;
	// カメラの見ている先(注視点/参照点)
	DirectX::SimpleMath::Vector3 refPos;
	// カメラの上方向ベクトル
	DirectX::SimpleMath::Vector3 vpVec;
	// 視野角
	float fovY;
	// アスペクト比
	float aspect;
	// ニアクリップ
	float nearClip;
	// ファ-クリップ
	float farClip;

	// ビュー行列
	DirectX::SimpleMath::Matrix view;
	// プロジェクション行列
	DirectX::SimpleMath::Matrix proj;
};

