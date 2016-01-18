### Package for Google Play
1. Install Crosswalk App Tools, see https://github.com/crosswalk-project/crosswalk-app-tools for details.
2. Change ```"xwalk_package_id"``` to ```"com.crosswalk.iapsampl"``` in manifest.json.
   Change ```"xwalk_extensions"``` to the path of the extensions in manifest.json.
3. Run
    ```
    crosswalk-pkg --targets="arm" --platform="android" --release \
    --crosswalk=/path/to/xwalk_app_template examples/iap
    ```
4. sign the apk manually, see https://developer.android.com/tools/publishing/app-signing.html#signing-manually for details.

### Package for XiaoMi Store
1. Install Crosswalk App Tools, see https://github.com/crosswalk-project/crosswalk-app-tools for details.
2. Change ```"xwalk_package_id"``` to ```"com.sdk.migame.payment"``` in manifest.json.
   Change ```"xwalk_extensions"``` to the path of the extensions in manifest.json.
   Add the additional permissions in your default AndroidManifest.xml.
    ```
    <uses-permission android:name="android.permission.GET_TASKS"/>
    
    <uses-permission android:name="com.xiaomi.sdk.permission.PAYMENT"/>
    <uses-permission android:name="android.permission.GET_ACCOUNTS"/>
    ```
3. Run
    ```
    crosswalk-pkg --targets="arm" --platform="android" --release \
    --crosswalk=/path/to/xwalk_app_template examples/iap
    ```
4. sign the apk manually, see https://developer.android.com/tools/publishing/app-signing.html#signing-manually for details.
