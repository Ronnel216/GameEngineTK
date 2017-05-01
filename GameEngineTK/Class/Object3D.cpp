/* Object3Dクラスのメンバ定義
author 2017/04/27
*/

#include "Object3D.h"

using namespace std;
using namespace DirectX;

Object3D::Object3D(const Model& model)
: _model(model){
}

Object3D::~Object3D() {
}

Object3D* Object3D::Create(const Model& model) {
	return new Object3D(model);
}

void Object3D::Update() {

}

void Object3D::Render() const{
}
