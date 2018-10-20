//
//  ViewController.swift
//  message2sync
//
//  Created by yuitora . on 20/10/2018.
//  Copyright © 2018 yuitora . All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITextFieldDelegate {

	//MARK: Properties
	@IBOutlet weak var messageText: UITextField!

	override func viewDidLoad() {
		super.viewDidLoad()
		
		messageText.delegate = self
		
	}
	
	func textFieldDidEndEditing(_ textField: UITextField) {
	
	}


}

