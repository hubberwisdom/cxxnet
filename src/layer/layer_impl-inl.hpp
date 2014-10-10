#ifndef CXXNET_LAYER_IMPL_INL_HPP_
#define CXXNET_LAYER_IMPL_INL_HPP_
/*!
 * \file layer-inl.hpp
 * \brief this file compiles all implementation of layers together
 * \author Bing Xu, Tianqi Chen
 */
#include "./layer.h"
#include "./activation_layer-inl.hpp"
#include "./convolution_layer-inl.hpp"
#include "./bias_layer-inl.hpp"
#include "./dropout_layer-inl.hpp"
/*

#include "./lrn_layer-inl.hpp"
#include "./flatten_layer-inl.hpp"
#include "./pooling_layer-inl.hpp"
#include "./softmax_layer-inl.hpp"
#include "./fullc_layer-inl.hpp"
*/
namespace cxxnet {
namespace layer {
template<typename xpu>
ILayer<xpu>* CreateLayer_(LayerType type,
                          mshadow::Random<xpu> *p_rnd,
                          const LabelInfo *label_info) {
  switch(type) {
    case kSigmoid: return new ActivationLayer<xpu, op::sigmoid, op::sigmoid_grad>();
    case kTanh: return new ActivationLayer<xpu, op::tanh, op::tanh_grad>();
    case kRectifiedLinear: return new ActivationLayer<xpu, op::relu, op::relu_grad>();
    case kSoftplus: return new ActivationLayer<xpu, op::softplus, op::softplus_grad>();
    case kConv: return new ConvolutionLayer<xpu>(p_rnd);
    case kBias: return new BiasLayer<xpu>();
    case kDropout: return new DropoutLayer<xpu>(p_rnd);
    default: utils::Error("unknown layer type");
  }
  /*
  switch(type) {
    case kSoftmax: return new SoftmaxLayer<xpu>(nodes_in, nodes_out, label_info);
    default: break;
  }
  // code for handling multiple connections return before here
  utils::Check(nodes_in.size() == 1 && nodes_out.size() == 1,
               "this layer can only take one input and output ");
  Node<xpu> *p_in = nodes_in[0];
  Node<xpu> *p_out = nodes_out[0];
  switch(type) {
    case kFullConnect: return new FullConnectLayer<xpu>(p_rnd, p_in, p_out);
    case kFlatten: return new FlattenLayer<xpu>(p_rnd, p_in, p_out);

    case kLRN: return new LRNLayer<xpu>(p_rnd, p_in, p_out);
    case kMaxPooling: return new PoolingLayer<mshadow::red::maximum, false, xpu>(p_rnd, p_in, p_out);
    case kSumPooling: return new PoolingLayer<mshadow::red::sum, false, xpu>(p_rnd, p_in, p_out);
    case kAvgPooling: return new PoolingLayer<mshadow::red::sum, true, xpu>(p_rnd, p_in, p_out);
    case kDropConn: return new DropConnLayer<xpu>(p_rnd, p_in, p_out);
    default: utils::Error("unknown layer type");
  }
  */
  return NULL;
}

}  // namespace layer
}  // namespace cxxnet
#endif
