// Small subset of the webL10n API by Fabien Cazenave for pdf.js extension.
(function(window) {
  var gLanguage = '';
  var gExternalLocalizerServices = null;
  var gReadyState = 'loading';

  // fetch an l10n objects
  function getL10nData(key) {
    var response = gExternalLocalizerServices.getStrings(key);
    var data = JSON.parse(response);
    if (!data) {
      console.warn('[l10n] #' + key + ' missing for [' + gLanguage + ']');
    }
    return data;
  }

  // replace {{arguments}} with their values
  function substArguments(text, args) {
    if (!args) {
      return text;
    }
    return text.replace(/\{\{\s*(\w+)\s*\}\}/g, function(all, name) {
      return (name in args ? args[name] : '{{' + name + '}}');
    });
  }

  // translate a string
  function translateString(key, args, fallback) {
    var i = key.lastIndexOf('.');
    var name, property;
    if (i >= 0) {
      name = key.substring(0, i);
      property = key.substring(i + 1);
    } else {
      name = key;
      property = 'textContent';
    }
    var data = getL10nData(name);