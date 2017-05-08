/* Object3Dクラス定義
author : Ryuna Tsuji
*/

#pragma once

#include <Model.h>
#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <Effects.h>
#include <CommonStates.h>
#include <SimpleMath.h>

class Object3D {
private:
	// 行列
	// ワールド
	DirectX::SimpleMath::Matrix _world;
	// ビュー
	DirectX::SimpleMath::Matrix _view;
	// プロジェクション
	DirectX::SimpleMath::Matrix _proj;
	// モデル
	const DirectX::Model& _model;

	// コンストラクタ
	Object3D(const DirectX::Model& model);

public:
	// デストラクタ
	~Object3D();

	// 生成
	static Object3D* Create(const DirectX::Model& model);

	// 更新
	void Update();

	// 描画
	void Render() const;

	// 平行移動
	DirectX::SimpleMath::Vector3 pos;
	// 回転行列
	DirectX::SimpleMath::Matrix rota;
	// 拡大縮小
	DirectX::SimpleMath::Matrix scale;

	// ワールド行列
	const DirectX::SimpleMath::Matrix& world() const {
		return _world;
	}
	void world(DirectX::SimpleMath::Vector3 pos) {
		_world = DirectX::SimpleMath::Matrix::CreateTranslation(pos);
	}
	void world(DirectX::SimpleMath::Matrix matrix) {
		_world = matrix;
	}

	// モデルデータ
	const DirectX::Model& model() const {
		return _model;
	}

};
