# Chrome Power

## Refer
[r0chrome](https://github.com/CrackerCat/r0chrome)

## Build

`autoninja -C out\Default chrome`

## Files Path

### Hardware

`src/third_party/blink/renderer/core/frame/navigator_concurrent_hardware.cc`

### UserAgent, System Type

`src/chrome/browser/chrome_content_browser_client.cc`

### Canvas

`src/third_party/blink/renderer/modules/canvas/canvas2d/base_rendering_context_2d.cc`
`BaseRenderingContext2D::measureText`

`src\third_party\blink\renderer\modules\canvas\canvas2d\canvas_path.cc`
`CanvasPath::arc`

### Audio

`src/third_party/blink/renderer/modules/offline_audio_context_power`
`OfflineAudioContext* OfflineAudioContext::Create`

`src/third_party/blink/renderer/modules/webaudio/base_audio_context.cc`

### Fonts

`src/third_party/blink/renderer/platform/fonts`

### Memory

`src/third_party/blink/renderer/core/frame/navigator_device_memory.cc`

### Platform

`src/third_party/blink/renderer/core/frame/navigator_id.cc`

### Screen, Color

`src/third_party/blink/renderer/core/frame/screen.cc`

### WebGL

`src/third_party/blink/renderer/modules/webgl/webgl_rendering_context_base.cc`

## Hide the "Missing API KEY" Info Bar

`src\chrome\browser\ui\startup\infobar_utils.cc`

```c++
    // if (!google_apis::HasAPIKeyConfigured())
      // GoogleApiKeysInfoBarDelegate::Create(infobar_manager);
```

## Handling of customized parameters

Goto `\content\browser\renderer_host\render_process_host_impl.cc`, add custom paramters to `kSwitchNames`


`src\third_party\blink\renderer\chrome_power\base\extended_parameters.cc`
